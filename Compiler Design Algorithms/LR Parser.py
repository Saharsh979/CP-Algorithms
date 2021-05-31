VN = []  # Non-terminal
VT = []  # Terminator
NFA = []  # NFA table
DFA = []  # DFA table
grammar = []  # Grammar read
doted_grammar = []  # Added grammar
VN2Int = {}  # Non-terminal mapping
VT2Int = {}  # Terminator mapping
action = []  # action table
goto = []  # goto 
DFA_node = []  # DFA node table
status_stack = []  # Status stack
symbol_stack = []  # Symbol stack
now_state = ''  # Stack top state
input_ch = ''  # Stack top character
input_str = ''  # Input string
location = 0  # Enter location
now_step = 0  # Current step


# Read grammar
def read_grammar(file_name):
    global grammar
    with open(file_name, 'r') as file:
        for line in file:
            line = line.replace('\n', "")
            grammar.append(line)
        file.close()


# Find terminal and non-terminal
def find_term_non():
    global grammar
    n = int(len(grammar))
    temp_vt = []
    l = 0
    for i in range(n):
        X, Y = grammar[i].split('->')
        if X not in VN:
            VN.append(X)
            VN2Int.update({X: l})
            l += 1
        for Yi in Y:
            temp_vt.append(Yi)

    m = 0
    for i in temp_vt:
        if i not in VN and i not in VT:
            VT.append(i)
            VT2Int.update({i: m})
            m += 1
    VT.append('#')
    VT2Int.update({'#': m})


# Add a dot at a certain position of the string
def add_char2str(grammar_i, i):
    grammar_i = grammar_i[0:i] + '.' + grammar_i[i:len(grammar_i)]
    return grammar_i


# Add some grammar
def add_dot():
    global doted_grammar
    j = 0
    n = 0
    for i in grammar:
        for k in range(len(i) - 2):
            doted_grammar.append([])
            doted_grammar[n].append(add_char2str(i, k + 3))
            doted_grammar[n].append('false')
            n += 1
        j += 1


# Show dotted grammar
def print_doted_grammar():
    print('----Grammar with dots----')
    j = 1
    for i in doted_grammar:
        print('%d.%s' % (j, i[0]))
        j += 1


# Show read grammar
def print_read_grammar():
    print('----Grammar read in----')
    j = 0
    for i in grammar:
        print('(%d)%s' % (j, i))
        j += 1


# Initialize NFA
def init_nfa():
    global NFA
    for row in range(len(doted_grammar)):
        NFA.append([])
        for col in range(len(doted_grammar)):
            NFA[row].append('')


# Find the location of the point
def find_pos_point(one_grammar):
    return one_grammar.find('.')


# Does the grammar start with start and start with'.'
def is_start(grammar_i, start):
    if grammar_i[0].find(start, 0, 1) + grammar_i[0].find('.', 3, 4) == 3:
        return True
    else:
        return False


# Find the grammar starting with start and starting with'.', and return the number
def find_node(start, grammar_id):
    num = 0
    for i in doted_grammar:
        if is_start(i, start):
            grammar_id[num] = doted_grammar.index(i)
            num += 1
    return num


# Construct NFA
def make_nfa():
    global NFA
    grammar_id = []
    for i in range(10):
        grammar_id.append('')
    init_nfa()
    i = 0
    for grammar_i in doted_grammar:
        pos_point = find_pos_point(grammar_i[0])  # Find the position of the point
        if not pos_point + 1 == len(grammar_i[0]):
            NFA[i][i + 1] = grammar_i[0][pos_point + 1]
            if grammar_i[0][pos_point + 1] in VN:  # Dot followed by non-terminal
                j = find_node(grammar_i[0][pos_point + 1], grammar_id)
                for k in range(j):
                    NFA[i][grammar_id[k]] = '*'
                    add_more(i, grammar_id[k])
        i += 1


# Find association
def add_more(i, j):
    global NFA
    grammar_id = []
    for k in range(10):
        grammar_id.append('')
    pos_point = find_pos_point(doted_grammar[j][0])
    if not pos_point + 1 == len(doted_grammar[j][0]):
        if doted_grammar[j][0][pos_point + 1] in VN:
            j = find_node(doted_grammar[j][0][pos_point + 1], grammar_id)
            for k in range(j):
                NFA[i][grammar_id[k]] = '*'
                add_more(i, grammar_id[k])


# Initialize DFA
def init_dfa():
    global DFA
    for row in range(len(doted_grammar)):
        DFA.append([])
        for col in range(len(doted_grammar)):
            DFA[row].append('')


# Connect
def add_state(to, fro):
    for i in range(len(doted_grammar)):
        if not NFA[to][i] == '' and not NFA[to][i] == '*':
            DFA[to][i] = NFA[to][i]
        if not NFA[fro][i] == '' and not NFA[fro][i] == '*':  # from connectable point
            DFA[to][i] = NFA[fro][i]


# Construct DFA
def make_dfa():
    global NFA, doted_grammar, DFA_node
    init_dfa()
    for i in range(len(doted_grammar)):
        DFA_node.append([])
        for j in range(len(doted_grammar)):
            DFA_node[i].append("")
    for i in range(len(doted_grammar)):
        if doted_grammar[i][1] == 'false':
            k = 0
            DFA_node[i][k] = doted_grammar[i][0]
            k += 1
            doted_grammar[i][1] = 'true'
            for j in range(len(doted_grammar)):
                if NFA[i][j] == '*':  # Has ε arc
                    DFA_node[i][k] = doted_grammar[j][0]
                    k += 1
                    doted_grammar[j][1] = 'true'
                    add_state(i, j)


# Initialize the LR analysis table
def init_lr_table():
    global doted_grammar, action, goto
    for i in range(len(doted_grammar)):
        action.append([])
        goto.append([])
        for j in range(len(VT)):
            action[i].append('')
        for j in range(len(VN)):
            goto[i].append(-1)


# Is there any agreement?
def need_protocol(point):
    global DFA_node
    if not DFA_node[point][0] == "":
        for i in range(10):
            if DFA_node[point][i].endswith('.'):
                return DFA_node[point][i]
            else:
                return None
    else:
        return None


# Find the grammar number based on the grammar content
def find_grammar(string):
    global grammar
    tmp = string[0: len(string) - 1]
    for i in range(len(grammar)):
        if tmp == grammar[i]:
            return i


# Fill in the LR analysis table
def fill_lr_table():
    global doted_grammar, VT2Int, VN2Int, VN
    init_lr_table()
    for i in range(len(doted_grammar)):
        if need_protocol(i):
            num = find_grammar(need_protocol(i))
            tmp = 'r' + str(num)
            for j in range(len(VT)):
                if i == 1:
                    action[i][VT2Int['#']] = 'acc'
                else:
                    action[i][j] = tmp
        else:
            for j in range(len(doted_grammar)):
                if not DFA[i][j] == '':
                    if DFA[i][j] in VN:
                        goto[i][VN2Int.get(DFA[i][j], -1)] = j
                    else:
                        tmp = 's' + str(j)
                        action[i][VT2Int.get(DFA[i][j], -1)] = tmp


# Display LR analysis table
def print_lr_table():
    global VT, VN, doted_grammar, action, goto
    # Header
    print('----LR analysis table----')
    print('\t\t|\t', end='')
    print(('%3s' % '') * (len(VT) - 2), end='')
    print('Action', end='')
    print(('%3s' % '') * (len(VT) - 2), end='')
    print('\t|\t', end='')
    print(('%3s' % '') * (len(VN) - 2), end='')
    print('GOTO', end='')
    print(('%3s' % '') * (len(VN) - 2), end='')
    print('\t|')
    print('\t\t\t', end='')
    for i in VT:
        print('%3s\t' % i, end='')
    print('\t|\t', end='')
    k = 0
    for i in VN:
        if not k == 0:
            print('%3s\t' % i, end='')
        k += 1
    print('\t|')
    for i in range(len(doted_grammar)):
        print('-----', end='')
    print()
    # Table body
    for i in range(len(doted_grammar)):
        print('%5d\t|\t' % i, end='')
        for j in range(len(VT)):
            print('%4s' % action[i][j], end='')
        print('\t|\t', end='')
        for j in range(len(VN)):
            if not j == 0:
                if not goto[i][j] == -1:
                    print('%4s' % goto[i][j], end='')
                else:
                    print('\t', end='')
        print('\t|')
    for i in range(len(doted_grammar)):
        print('-----', end='')
    print()


# Determine whether the analysis is complete
def is_end():
    if input_str[location:len(input_str)] == '#':
        if symbol_stack[-1] == 'X' and symbol_stack[-2] == '#':
            return True
        else:
            return False
    else:
        return False


# Output
def output():
    global now_step, status_stack, symbol_stack, input_str, now_state
    print('%d\t\t' % now_step, end='')
    now_step += 1
    print('%-20s' % status_stack, end='')
    print('%-25s' % symbol_stack, end='')
    print('%-22s' % input_str[location:len(input_str)], end='')


# Count the number of right parts of the production
def count_right_num(grammar_i):
    return len(grammar_i) - 3


# Statute
def do_stipulations():
    global status_stack, input_str, symbol_stack, location, now_state, input_ch
    print('----Anysis Process----')
    print("index\t\t", end='')
    print('%-17s' % 'Status', end='')
    print('%-22s' % 'Symbol', end='')
    print('%-20s' % 'Input', end='')
    print('Action')
    for i in range(len(doted_grammar)):
        print('-----------', end='')
    print()
    symbol_stack.append('#')
    status_stack.append(0)
    while not is_end():
        now_state = status_stack[-1]
        input_ch = input_str[location]
        output()
        find = action[now_state][VT2Int[input_ch]]
        if find[0] == 's':
            symbol_stack.append(input_ch)
            status_stack.append(int(find[1]))
            location += 1
            print('action[%s][%s]=s%s, that is, status=%s on the stack' % (now_state, input_ch, find[1], find[1]))
        elif find[0] == 'r':
            num = int(find[1])
            g = grammar[num]
            right_num = count_right_num(g)
            for i in range(right_num):
                status_stack.pop()
                symbol_stack.pop()
            symbol_stack.append(g[0])
            now_state = status_stack[-1]
            symbol_ch = symbol_stack[-1]
            find = goto[now_state][VN2Int.get(symbol_ch, -1)]
            if find == -1:
                print('****Analysis failed****')
                break
            status_stack.append(find)
            print('r%s: Use %s protocol, and GOTO(%s, %s)=%s push into the stack' % (num, g, status_stack[-2], symbol_stack[-1], find))
        else:
            break
    print("acc:OK")


if __name__ == '__main__':
    # Read in the grammar, add some to the grammar
    read_grammar('src.txt')
    add_dot()
    print_read_grammar()
    print_doted_grammar()
    find_term_non()
    # Construct NFA
    make_nfa()
    # Construct DFA
    make_dfa()
    # Construction analysis table
    fill_lr_table()
    print_lr_table()
    # Statute
    input_str = 'abab#'
    do_stipulations()
