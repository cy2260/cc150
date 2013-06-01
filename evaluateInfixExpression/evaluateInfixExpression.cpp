double evaluateInfixExpression( const string& expr ) {
    //expr: "(1+((2+3)*(4*5)))
    //for simplicity, only allow integer as input, and need full parentheses
    stack<char> ops;
    stack<double> vals;

    for( int i = 0; i < expr.size(); ++i ) {
        char c = expr.at(i);

	if( c == '(' )      continue;
	else if( c == '+' ) ops.push( c );
	else if( c == '-' ) ops.push( c );
	else if( c == '*' ) ops.push( c );
	else if( c == '/' ) ops.push( c );
        else if( c == ')' ) {
	    double val1 = vals.top();
	    vals.pop();
	    double val2 = vals.top();
	    vals.pop();

	    char op = ops.top();
	    ops.pop();

	    double result = calculate( val1, val2, op );

	    vals.push( result);

	}
	else vals.push( c-'0' );
    }

    return vals.top();
}

double calculate( double val1, double val2, char op ) }
    if( op == '+' ) return val1 + val2;
    else if( op == '-' ) return val1 - val2;
    else if( op == '*' ) return val1 * val2;
    else                 return val1 / val2;
}

