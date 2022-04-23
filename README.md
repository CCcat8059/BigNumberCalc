# BigNumber
## BN_ArithmeticOperator
### operator +
- BNint and BNint
- BNint and BNfloat  
TODO
- BNfloat and BNfloat  
TODO

### operator -
- BNint and BNint
- BNint and BNfloat  
TODO
- BNfloat and BNfloat  
TODO

## BN_AssignmentOperator
### operator =
- BN to BN

## BN_Basic
### Constructor
- BN()
- BN(string)
- BN(BN) (copy constructor)

## BN_OtherOperator
### operator <<
- denominator is 10^n
- other numerator and denominator (e.g 1/3, 3/7)  
TODO

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
TODO
### basicDiv
basic division for integer  
TODO
### abs
return |num|
