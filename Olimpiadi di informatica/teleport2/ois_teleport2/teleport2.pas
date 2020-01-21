{ NOTE: it is recommended to use this even if you don't understand the following code. }

Uses math;

{ input data }
var
    T, i                        : longint;
    Xa, Ya, Xb, Yb, Xc, Yc, R   : longint;
    res                         : Double;

begin
{
    uncomment the following lines if you want to read/write from files
    assign(input,  'input.txt');  reset(input);
    assign(output, 'output.txt'); rewrite(output);
}

    readln(T);
    for i:=0 to T-1 do
    begin
        readln(Xa, Ya, Xb, Yb, Xc, Yc, R);

        { insert your code here }

        res := 1.453128314;

        { print result (round down and print six decimals) }
        { DO NOT EDIT! }
        res := Trunc(res * 1000000) / 1000000;
        writeln(res:1:6);
    end;
end.
