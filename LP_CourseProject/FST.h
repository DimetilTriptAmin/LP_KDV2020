#pragma once
#include <iostream>

#define delim "|"

#define INCLUDENODES	FST::NODE (1, FST::RELATION('#', 1)),\
						FST::NODE (1, FST::RELATION('�', 2)),\
						FST::NODE (1, FST::RELATION('�', 3)),\
						FST::NODE (1, FST::RELATION('�', 4)),\
						FST::NODE (1, FST::RELATION('�', 5)),\
						FST::NODE (1, FST::RELATION('�', 6)),\
						FST::NODE (1, FST::RELATION('�', 7)),\
						FST::NODE (1, FST::RELATION('�', 8)),\
						FST::NODE (1, FST::RELATION('�', 9)),\
						FST::NODE()

//8
#define INTEGERNODES	FST::NODE (1, FST::RELATION('�', 1)),\
						FST::NODE (1, FST::RELATION('�', 2)),\
						FST::NODE (1, FST::RELATION('�', 3)),\
						FST::NODE (1, FST::RELATION('�', 4)),\
						FST::NODE()

//7
#define STRINGNODES	FST::NODE (1, FST::RELATION('�', 1)),\
					FST::NODE (1, FST::RELATION('�', 2)),\
					FST::NODE (1, FST::RELATION('�', 3)),\
					FST::NODE (1, FST::RELATION('�', 4)),\
					FST::NODE (1, FST::RELATION('�', 5)),\
					FST::NODE()

#define IDNODES		FST::NODE (240,	\
									FST::RELATION('a', 1),FST::RELATION('b', 1),FST::RELATION('c', 1),FST::RELATION('d', 1),FST::RELATION('e', 1),  \
									FST::RELATION('f', 1),FST::RELATION('g', 1),FST::RELATION('h', 1),FST::RELATION('i', 1),FST::RELATION('j', 1),  \
									FST::RELATION('k', 1),FST::RELATION('l', 1),FST::RELATION('m', 1),FST::RELATION('n', 1),FST::RELATION('o', 1),  \
									FST::RELATION('p', 1),FST::RELATION('q', 1),FST::RELATION('r', 1),FST::RELATION('s', 1),FST::RELATION('t', 1),  \
									FST::RELATION('u', 1),FST::RELATION('v', 1),FST::RELATION('w', 1),FST::RELATION('x', 1),FST::RELATION('y', 1),  \
									FST::RELATION('z', 1),\
									FST::RELATION('A', 1),FST::RELATION('B', 1),FST::RELATION('C', 1),FST::RELATION('D', 1),FST::RELATION('E', 1),  \
									FST::RELATION('F', 1),FST::RELATION('G', 1),FST::RELATION('H', 1),FST::RELATION('I', 1),FST::RELATION('J', 1),  \
									FST::RELATION('K', 1),FST::RELATION('L', 1),FST::RELATION('M', 1),FST::RELATION('N', 1),FST::RELATION('O', 1),  \
									FST::RELATION('P', 1),FST::RELATION('Q', 1),FST::RELATION('R', 1),FST::RELATION('S', 1),FST::RELATION('T', 1),  \
									FST::RELATION('U', 1),FST::RELATION('V', 1),FST::RELATION('W', 1),FST::RELATION('X', 1),FST::RELATION('Y', 1),  \
									FST::RELATION('Z', 1),\
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),\
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1), \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									\
									FST::RELATION('a', 2),FST::RELATION('b', 2),FST::RELATION('c', 2),FST::RELATION('d', 2),FST::RELATION('e', 2),  \
									FST::RELATION('f', 2),FST::RELATION('g', 2),FST::RELATION('h', 2),FST::RELATION('i', 2),FST::RELATION('j', 2),  \
									FST::RELATION('k', 2),FST::RELATION('l', 2),FST::RELATION('m', 2),FST::RELATION('n', 2),FST::RELATION('o', 2),  \
									FST::RELATION('p', 2),FST::RELATION('q', 2),FST::RELATION('r', 2),FST::RELATION('s', 2),FST::RELATION('t', 2),  \
									FST::RELATION('u', 2),FST::RELATION('v', 2),FST::RELATION('w', 2),FST::RELATION('x', 2),FST::RELATION('y', 2),  \
									FST::RELATION('z', 2),\
									FST::RELATION('A', 2),FST::RELATION('B', 2),FST::RELATION('C', 2),FST::RELATION('D', 2),FST::RELATION('E', 2),  \
									FST::RELATION('F', 2),FST::RELATION('G', 2),FST::RELATION('H', 2),FST::RELATION('I', 2),FST::RELATION('J', 2),  \
									FST::RELATION('K', 2),FST::RELATION('L', 2),FST::RELATION('M', 2),FST::RELATION('N', 2),FST::RELATION('O', 2),  \
									FST::RELATION('P', 2),FST::RELATION('Q', 2),FST::RELATION('R', 2),FST::RELATION('S', 2),FST::RELATION('T', 2),  \
									FST::RELATION('U', 2),FST::RELATION('V', 2),FST::RELATION('W', 2),FST::RELATION('X', 2),FST::RELATION('Y', 2),  \
									FST::RELATION('Z', 2),\
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),\
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2), \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2)),  \
				FST::NODE (250,	FST::RELATION('1', 1),FST::RELATION('2', 1),FST::RELATION('3', 1),FST::RELATION('4', 1),FST::RELATION('5', 1),  \
									FST::RELATION('6', 1),FST::RELATION('7', 1),FST::RELATION('8', 1),FST::RELATION('9', 1),FST::RELATION('0', 1),  \
									FST::RELATION('a', 1),FST::RELATION('b', 1),FST::RELATION('c', 1),FST::RELATION('d', 1),FST::RELATION('e', 1),  \
									FST::RELATION('f', 1),FST::RELATION('g', 1),FST::RELATION('h', 1),FST::RELATION('i', 1),FST::RELATION('j', 1),  \
									FST::RELATION('k', 1),FST::RELATION('l', 1),FST::RELATION('m', 1),FST::RELATION('n', 1),FST::RELATION('o', 1),  \
									FST::RELATION('p', 1),FST::RELATION('q', 1),FST::RELATION('r', 1),FST::RELATION('s', 1),FST::RELATION('t', 1),  \
									FST::RELATION('u', 1),FST::RELATION('v', 1),FST::RELATION('w', 1),FST::RELATION('x', 1),FST::RELATION('y', 1),  \
									FST::RELATION('z', 1),\
									FST::RELATION('A', 1),FST::RELATION('B', 1),FST::RELATION('C', 1),FST::RELATION('D', 1),FST::RELATION('E', 1),  \
									FST::RELATION('F', 1),FST::RELATION('G', 1),FST::RELATION('H', 1),FST::RELATION('I', 1),FST::RELATION('J', 1),  \
									FST::RELATION('K', 1),FST::RELATION('L', 1),FST::RELATION('M', 1),FST::RELATION('N', 1),FST::RELATION('O', 1),  \
									FST::RELATION('P', 1),FST::RELATION('Q', 1),FST::RELATION('R', 1),FST::RELATION('S', 1),FST::RELATION('T', 1),  \
									FST::RELATION('U', 1),FST::RELATION('V', 1),FST::RELATION('W', 1),FST::RELATION('X', 1),FST::RELATION('Y', 1),  \
									FST::RELATION('Z', 1),\
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),\
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1), \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									\
									FST::RELATION('1', 2),FST::RELATION('2', 2),FST::RELATION('3', 2),FST::RELATION('4', 2),FST::RELATION('5', 2),  \
									FST::RELATION('6', 2),FST::RELATION('7', 2),FST::RELATION('8', 2),FST::RELATION('9', 2),FST::RELATION('0', 2),  \
									FST::RELATION('a', 2),FST::RELATION('b', 2),FST::RELATION('c', 2),FST::RELATION('d', 2),FST::RELATION('e', 2),  \
									FST::RELATION('f', 2),FST::RELATION('g', 2),FST::RELATION('h', 2),FST::RELATION('i', 2),FST::RELATION('j', 2),  \
									FST::RELATION('k', 2),FST::RELATION('l', 2),FST::RELATION('m', 2),FST::RELATION('n', 2),FST::RELATION('o', 2),  \
									FST::RELATION('p', 2),FST::RELATION('q', 2),FST::RELATION('r', 2),FST::RELATION('s', 2),FST::RELATION('t', 2),  \
									FST::RELATION('u', 2),FST::RELATION('v', 2),FST::RELATION('w', 2),FST::RELATION('x', 2),FST::RELATION('y', 2),  \
									FST::RELATION('z', 2),\
									FST::RELATION('A', 2),FST::RELATION('B', 2),FST::RELATION('C', 2),FST::RELATION('D', 2),FST::RELATION('E', 2),  \
									FST::RELATION('F', 2),FST::RELATION('G', 2),FST::RELATION('H', 2),FST::RELATION('I', 2),FST::RELATION('J', 2),  \
									FST::RELATION('K', 2),FST::RELATION('L', 2),FST::RELATION('M', 2),FST::RELATION('N', 2),FST::RELATION('O', 2),  \
									FST::RELATION('P', 2),FST::RELATION('Q', 2),FST::RELATION('R', 2),FST::RELATION('S', 2),FST::RELATION('T', 2),  \
									FST::RELATION('U', 2),FST::RELATION('V', 2),FST::RELATION('W', 2),FST::RELATION('X', 2),FST::RELATION('Y', 2),  \
									FST::RELATION('Z', 2),\
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),\
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),  \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2), \
									FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2),FST::RELATION('�', 2)),  \
				FST::NODE()

//8
#define FUNCTIONNODES	FST::NODE (1, FST::RELATION('�', 1)),\
						FST::NODE (1, FST::RELATION('�', 2)),\
						FST::NODE (1, FST::RELATION('�', 3)),\
						FST::NODE (1, FST::RELATION('�', 4)),\
						FST::NODE (1, FST::RELATION('�', 5)),\
						FST::NODE (1, FST::RELATION('�', 6)),\
						FST::NODE (1, FST::RELATION('�', 7)),\
						FST::NODE()
 //9
#define DECLARENODES	FST::NODE (1, FST::RELATION('�', 1)),\
						FST::NODE (1, FST::RELATION('�', 2)),\
						FST::NODE (1, FST::RELATION('\'', 3)),\
						FST::NODE (1, FST::RELATION('�', 4)),\
						FST::NODE (1, FST::RELATION('�', 5)),\
						FST::NODE (1, FST::RELATION('�', 6)),\
						FST::NODE (1, FST::RELATION('�', 7)),\
						FST::NODE (1, FST::RELATION('�', 8)),\
						FST::NODE()

//8
#define PRINTNODES	FST::NODE (1, FST::RELATION('�', 1)),\
				FST::NODE (1, FST::RELATION('�', 2)),\
				FST::NODE (1, FST::RELATION('�', 3)),\
				FST::NODE (1, FST::RELATION('�', 4)),\
				FST::NODE (1, FST::RELATION('�', 5)),\
				FST::NODE (1, FST::RELATION('�', 6)),\
				FST::NODE (1, FST::RELATION('�', 7)),\
				FST::NODE()

//8
#define RETURNNODES	FST::NODE (1, FST::RELATION('�', 1)),\
				FST::NODE (1, FST::RELATION('�', 2)),\
				FST::NODE (1, FST::RELATION('�', 3)),\
				FST::NODE (1, FST::RELATION('�', 4)),\
				FST::NODE (1, FST::RELATION('�', 5)),\
				FST::NODE (1, FST::RELATION('�', 6)),\
				FST::NODE (1, FST::RELATION('�', 7)),\
				FST::NODE()

#define WHILENODES	FST::NODE (1, FST::RELATION('�', 1)),\
				FST::NODE (1, FST::RELATION('�', 2)),\
				FST::NODE (1, FST::RELATION('�', 3)),\
				FST::NODE (1, FST::RELATION('�', 4)),\
				FST::NODE (1, FST::RELATION('�', 5)),\
				FST::NODE (1, FST::RELATION('�', 6)),\
				FST::NODE()

#define BOOLNODES	FST::NODE (1, FST::RELATION('�', 1)),\
					FST::NODE (1, FST::RELATION('�', 2)),\
					FST::NODE (1, FST::RELATION('�', 3)),\
					FST::NODE (1, FST::RELATION('�', 4)),\
					FST::NODE (1, FST::RELATION('�', 5)),\
					FST::NODE (1, FST::RELATION('�', 6)),\
					FST::NODE (1, FST::RELATION('�', 7)),\
					FST::NODE()
#define IFNODES		FST::NODE (1, FST::RELATION('�', 1)),\
					FST::NODE (1, FST::RELATION('�', 2)),\
					FST::NODE (1, FST::RELATION('�', 3)),\
					FST::NODE (1, FST::RELATION('�', 4)),\
					FST::NODE()
#define ELSENODES	FST::NODE (1, FST::RELATION('�', 1)),\
					FST::NODE (1, FST::RELATION('�', 2)),\
					FST::NODE (1, FST::RELATION('�', 3)),\
					FST::NODE (1, FST::RELATION('�', 4)),\
					FST::NODE (1, FST::RELATION('�', 5)),\
					FST::NODE()

#define TRUENODES	FST::NODE (1, FST::RELATION('�', 1)),\
					FST::NODE (1, FST::RELATION('�', 2)),\
					FST::NODE (1, FST::RELATION('�', 3)),\
					FST::NODE()

#define FALSENODES	FST::NODE (1, FST::RELATION('�', 1)),\
					FST::NODE (1, FST::RELATION('�', 2)),\
					FST::NODE()

#define OPERATORNODES	FST::NODE (4, FST::RELATION('+', 1), FST::RELATION('-', 1), FST::RELATION('/', 1),FST::RELATION('*', 1)),\
						FST::NODE()


#define OPERATORBIGGER			FST::NODE (1, FST::RELATION('>', 1)),\
								FST::NODE()

#define OPERATORSMALLER			FST::NODE (1, FST::RELATION('<', 1)),\
								FST::NODE()

#define OPERATORBIGGEREQUAL		FST::NODE (1, FST::RELATION('>', 1)),\
								FST::NODE (1, FST::RELATION('=', 2)),\
								FST::NODE()

#define OPERATORSMALLEREQUAL	FST::NODE (1, FST::RELATION('<', 1)),\
								FST::NODE (1, FST::RELATION('=', 2)),\
								FST::NODE()

#define OPERATORNOTEQUAL		FST::NODE (1, FST::RELATION('!', 1)),\
								FST::NODE (1, FST::RELATION('=', 2)),\
								FST::NODE()

#define OPERATOREQUAL			FST::NODE (1, FST::RELATION('=', 1)),\
								FST::NODE (1, FST::RELATION('=', 2)),\
								FST::NODE()

#define STRLITNODES	FST::NODE (1, FST::RELATION('"', 1)),\
					FST::NODE (201,	FST::RELATION('1', 1),FST::RELATION('2', 1),FST::RELATION('3', 1),FST::RELATION('4', 1),FST::RELATION('5', 1),  \
									FST::RELATION('6', 1),FST::RELATION('7', 1),FST::RELATION('8', 1),FST::RELATION('9', 1),FST::RELATION('0', 1),  \
									FST::RELATION('a', 1),FST::RELATION('b', 1),FST::RELATION('c', 1),FST::RELATION('d', 1),FST::RELATION('e', 1),  \
									FST::RELATION('f', 1),FST::RELATION('g', 1),FST::RELATION('h', 1),FST::RELATION('i', 1),FST::RELATION('j', 1),  \
									FST::RELATION('k', 1),FST::RELATION('l', 1),FST::RELATION('m', 1),FST::RELATION('n', 1),FST::RELATION('o', 1),  \
									FST::RELATION('p', 1),FST::RELATION('q', 1),FST::RELATION('r', 1),FST::RELATION('s', 1),FST::RELATION('t', 1),  \
									FST::RELATION('u', 1),FST::RELATION('v', 1),FST::RELATION('w', 1),FST::RELATION('x', 1),FST::RELATION('y', 1),  \
									FST::RELATION('z', 1),\
									FST::RELATION('A', 1),FST::RELATION('B', 1),FST::RELATION('C', 1),FST::RELATION('D', 1),FST::RELATION('E', 1),  \
									FST::RELATION('F', 1),FST::RELATION('G', 1),FST::RELATION('H', 1),FST::RELATION('I', 1),FST::RELATION('J', 1),  \
									FST::RELATION('K', 1),FST::RELATION('L', 1),FST::RELATION('M', 1),FST::RELATION('N', 1),FST::RELATION('O', 1),  \
									FST::RELATION('P', 1),FST::RELATION('Q', 1),FST::RELATION('R', 1),FST::RELATION('S', 1),FST::RELATION('T', 1),  \
									FST::RELATION('U', 1),FST::RELATION('V', 1),FST::RELATION('W', 1),FST::RELATION('X', 1),FST::RELATION('Y', 1),  \
									FST::RELATION('Z', 1),\
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),\
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1), \
									FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),FST::RELATION('�', 1),  \
									FST::RELATION('!', 1),FST::RELATION('"', 1),FST::RELATION('�', 1),FST::RELATION(';', 1),FST::RELATION('%', 1),  \
									FST::RELATION(':', 1),FST::RELATION('?', 1),FST::RELATION('*', 1),FST::RELATION('(', 1),FST::RELATION(')', 1),  \
									FST::RELATION('-', 1),FST::RELATION('+', 1),FST::RELATION('\\', 1),FST::RELATION('/', 1),FST::RELATION('<', 1), \
									FST::RELATION('>', 1),FST::RELATION('{', 1),FST::RELATION('}', 1),FST::RELATION('[', 1),FST::RELATION(']', 1),  \
									FST::RELATION('~', 1), FST::RELATION(' ', 1),FST::RELATION('.', 1),\
									FST::RELATION('"', 2)),\
					FST::NODE()

//3 
#define INTLITNODES	FST::NODE (3, FST::RELATION('8', 1),FST::RELATION('2', 1),FST::RELATION('-', 0)),\
					FST::NODE (2, FST::RELATION('x', 2),FST::RELATION('�', 2)),\
					FST::NODE (16, FST::RELATION('0', 3),FST::RELATION('1', 3),FST::RELATION('2', 3),FST::RELATION('3', 3),FST::RELATION('4', 3),FST::RELATION('5', 3),\
								   FST::RELATION('6', 3),FST::RELATION('7', 3),\
								   FST::RELATION('0', 4),FST::RELATION('1', 4),FST::RELATION('2', 4),FST::RELATION('3', 4),FST::RELATION('4', 4),FST::RELATION('5', 4),\
							       FST::RELATION('6', 4),FST::RELATION('7', 4)),\
					FST::NODE (16, FST::RELATION('0', 3),FST::RELATION('1', 3),FST::RELATION('2', 3),FST::RELATION('3', 3),FST::RELATION('4', 3),FST::RELATION('5', 3),\
								   FST::RELATION('6', 3),FST::RELATION('7', 3),\
								   FST::RELATION('0', 4),FST::RELATION('1', 4),FST::RELATION('2', 4),FST::RELATION('3', 4),FST::RELATION('4', 4),FST::RELATION('5', 4),\
							       FST::RELATION('6', 4),FST::RELATION('7', 4)),\
					FST::NODE()

#define LEFTBRACENODES	FST::NODE (1, FST::RELATION('{', 1)),\
				FST::NODE()

#define BRACELETNODES	FST::NODE (1, FST::RELATION('}', 1)),\
				FST::NODE()

#define LEFTHESISNODES	FST::NODE (1, FST::RELATION('(', 1)),\
				FST::NODE()

#define RIGHTHESISNODES	FST::NODE (1, FST::RELATION(')', 1)),\
				FST::NODE()

#define ASSIGNNODES	FST::NODE (1, FST::RELATION('=', 1)),\
				FST::NODE()

#define SEMICOLONNODES	FST::NODE (1, FST::RELATION(';', 1)),\
				FST::NODE()

#define COMMANODES	FST::NODE (1, FST::RELATION(',', 1)),\
				FST::NODE()


namespace FST
{
	struct RELATION // �����:������ -> ������� ����� ��������� ��
	{
		char symbol;  // ������ ��������
		short nnode; // ����� ������� �������
		RELATION(
			char c = 0x00, /// ������ ��������
			short ns = NULL // ����� ���������
		);
	};

	struct NODE // ������� ����� ���������
	{
		short n_relation; // ���������� ������������ �����
		RELATION* relations; // ������������ �����
		NODE();
		NODE(
			short n, // ���������� ������������ �����
			RELATION rel, ... // ������ �����
		);
	};
	struct FST // ������������������� �������� �������
	{
		char* string; // ������� (������ ����������� 0�00)
		short position; // ������� ������� � �������
		short nstates;  // ���������� ��������� ��������
		NODE* nodes; // ���� ���������: [0] - ��������� ��������� [nstate-1] - ��������
		short* rstates; // ��������� ��������� �������� �� ������ �������
		FST(
			char* s, // ������� 
			short ns, // ���������� ��������� ��������
			NODE n, ... // ������ ��������� (���� ���������)
		);
	};
	bool execute( // ��������� ������������� �������
		FST& fst // ������������������� �������
	);

	void FstDelete(FST fst);

}