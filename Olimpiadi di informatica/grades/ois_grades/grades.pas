{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXN = 1000000;

{ input data }
var
    N, i  : longint;
    G     : array[0..MAXN-1] of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(N);
    for i:=0 to N-1 do
        read(G[i]);
    readln();

    { insert your code here }

    writeln(42); { print result }
end.
