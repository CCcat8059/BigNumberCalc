# BigNumber
## BN_ArithmeticOperator
### operator +
- BNint and BNint
  + '+' and '+'
- BNint and BNfloat
- BNfloat and BNfloat

### operator -
- BNint and BNint
  + '+' and '+'
- BNint and BNfloat
- BNfloat and BNfloat

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
- only for denominator is 10^n

## BN_RelationalOperator
### operator ==
#### BN to BN
- simple compare string numerator and sign (no denominator)

### operator !=
#### BN to BN
- !(a == b)

### operator >
#### BN to BN
- only integer compare (no compare denominator)

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
