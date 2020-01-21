{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXN = 1000000;

{ input data }
var
    N, i  : longint;
    P     : array[0..MAXN-1] of longint;
    res   : Int64;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N);
    for i:=0 to N-1 do
        read(P[i]);
    readln();

    { insert your code here }
    res := 42;

    writeln(res); { print result }
end.
