{ NOTE: it is recommended to use this even if you don't understand the following code. }

{ constraints }
const
    MAXT = 10000;

{ input data }
var
    T, i  : longint;
    N     : array[0..MAXT-1] of longint;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(T);
    for i:=0 to T-1 do
    begin
        read(N[i]);
        
        { insert your code here }


        write(42); { print result }
        write(' ');
    end;
    writeln()
end.
