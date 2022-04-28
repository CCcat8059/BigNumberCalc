# BigNumber
## BN_ArithmeticOperator
### operator +
- BNint and BNint
- BNint and BNfloat
- BNfloat and BNfloat
- BNint and int (or int and BNint)

### operator -
- BNint and BNint
- BNint and BNfloat
- BNfloat and BNfloat
- BNint and int (or int and BNint)

### operator *
- BNint and BNint
- BNint and BNfloat
- BNfloat and BNfloat
- BNint and int (or int and BNint)

### operator /
- BNint and BNint
- BNint and BNfloat
- BNfloat and BNfloat
- BNint and int (or int and BNint)

### operator %
- BNint and BNint
- BNint and int (or int and BNint)


## BN_AssignmentOperator
### operator =
- BN to BN
- BN to int
### operator +=
- BN to BN
- BN to int
### operator -=
- BN to BN
- BN to int
### operator *=
- BN to BN
- BN to int
### operator /=
- BN to BN
- BN to int
### operator %=
- BN to BN
- BN to int


## BN_Basic
### Constructor
- BN()
- BN(string)
- BN(BN) (copy constructor)
- BN(int)
- BN(numerator, denominator)


## BN_OtherOperator
### operator <<
- denominator is 10^n
- other numerator and denominator (e.g 1/3, 3/7)


## BN_RelationalOperator
### operator ==
#### BN to BN
- compare numerator (both denominator are 1) 
- make denominator be same and compare  
TODO

### operator !=
#### BN to BN
- !(a == b)

### operator >
#### BN to BN
- integer compare (both denominator are 1)
- make denominator be same and compare  
TODO

### operator >=
#### BN to BN
- (a > b || a == b)

### operator <
#### BN to BN
- !(a > b || a == b)

### operator <=
#### BN to BN
- !(a > b)


## utility
### basicAdd
basic addition for integer
### basicSub
basic substruction for integer
### basicMul
basic multipication for integer
### basicDiv
basic division for integer

### abs
return |num|
### reciprocal
return 1/num
### gcd
return gcd
### lcm
return lcm
### power
return base ^ num  
TODO
### factorial
return num!
