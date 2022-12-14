function G = printReactions(nuf,nub,names)

nr = size(nuf,1);
ns = size(nuf,2);

for r = 1:nr
    fprintf("Reaction %d:  ", r);
    % forward
    hasHead = false;
    for s = 1:ns
        nu = nuf(r,s);
        if nu
            if hasHead
                fprintf(" + ");
            end
            hasHead = true;
            if nu == 1
                fprintf("%s", string(names(s)));
            else
                fprintf("%d%s", nu, string(names(s)));
            end
        end
    end
    fprintf(" == ");
    %back
    hasHead = false;
    for s = 1:ns
        nu = nub(r,s);
        if nu
            if hasHead
                fprintf(" + ");
            end
            hasHead = true;
            if nu == 1
                fprintf("%s", string(names(s)));
            else
                fprintf("%d%s", nu, string(names(s)));
            end
        end
    end
    fprintf("\n");
end

AdjMat = zeros(nr+ns);
AdjMat(1:ns, ns + 1: ns + nr) = nuf';
AdjMat(ns + 1: ns + nr, 1:ns) = nub;
Name = [reshape(string(names),[],1); compose("r_%d", 1:nr)'];
ntable = table(Name);

G = digraph(AdjMat, ntable);
plot(G, 'Layout',"layered", 'MarkerSize', [ones(ns,1)*6;ones(nr,1)*16],...
    'Marker',[repmat(".",ns,1);repmat("s",nr,1)]);
