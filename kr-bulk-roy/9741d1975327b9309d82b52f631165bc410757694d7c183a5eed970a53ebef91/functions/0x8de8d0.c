
int FUN_008de8d0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  byte *_Dst;
  int iVar1;
  undefined4 *in_ECX;
  undefined1 local_1ac [416];
  int local_c;
  undefined4 *local_8;
  
  local_c = 0;
  FUN_008dd080(0x1000);
  _memset(in_ECX,0,0xb0);
  in_ECX[0xc] = 0x10000;
  in_ECX[0xf] = 0x10000;
  *in_ECX = 0xffff;
  in_ECX[1] = 0xffff;
  in_ECX[2] = 0xffff;
  in_ECX[3] = 0xffff;
  in_ECX[4] = 0xffff;
  in_ECX[5] = 0xffff;
  in_ECX[0x20] = 0xffff;
  in_ECX[0x21] = 0xffff;
  in_ECX[0x22] = 0xffff;
  in_ECX[0x2b] = 0xffff;
  in_ECX[8] = 0xff9c0000;
  in_ECX[9] = 0x320000;
  in_ECX[0xb] = 2;
  in_ECX[0x27] = 0x2210;
  iVar1 = FUN_008dde20(param_1,&local_c,&local_8);
  if (iVar1 == 0) {
    iVar1 = FUN_008dd750(local_1ac,(int)local_8 + local_c);
  }
  FUN_008ddf70();
  if (iVar1 != 0) {
    return iVar1;
  }
  if (in_ECX[0x21] != 0xffff) {
    return 0;
  }
  if ((in_ECX[0x1d] != 0) && (in_ECX[0x1e] != 0)) {
    _Dst = (byte *)(in_ECX + 0x2c);
    _memset(_Dst,0,0x168);
    in_ECX[0x5e] = 7;
    in_ECX[0x5f] = 1;
    in_ECX[0x7f] = 0xffffffff;
    in_ECX[0x81] = 0xf5c;
    in_ECX[0x5d] = 0x27a000;
    FUN_008dd080(0x2000,_Dst,param_4);
    iVar1 = FUN_008b97e0(param_2,in_ECX[0x1d] + param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = FUN_008babe0(param_2,in_ECX[0x1e]);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = FUN_008dd750(local_1ac,*(undefined4 *)(param_2 + 0x24));
    FUN_008baca0(param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
    *_Dst = *_Dst & 0xfe;
  }
  iVar1 = 0;
  if ((in_ECX[0x83] != 0) &&
     (iVar1 = FUN_008b97e0(param_2,in_ECX[0x1d] + in_ECX[0x83] + param_3), iVar1 == 0)) {
    local_8 = in_ECX + 0x86;
    iVar1 = FUN_008dd9f0(1);
    if (iVar1 == 0) {
      iVar1 = FUN_008ddce0(local_8,in_ECX + 0x8e,0);
    }
  }
  return iVar1;
}

