clear;
for ipro=0:3
    fn=['proc00000',num2str(ipro),'_vs.bin'];
    fnx=['proc00000',num2str(ipro),'_x.bin'];
    fnz=['proc00000',num2str(ipro),'_z.bin'];
    fp=fopen(fn);
    fpx=fopen(fnx);
    fpz=fopen(fnz);
    fifo=dir(fn);
    fsize=fifo.bytes;
    [x,c]=fread(fpx,fsize,'float');
    [z,c]=fread(fpz,fsize,'float');
    [v,c]=fread(fp,fsize,'float');
    vrange=max(v)-min(v);
    for k=1:fsize/4
        plot(x(k),z(k),'.','Color',[v(k)/vrange 0 0]);
        hold on;
    end
end