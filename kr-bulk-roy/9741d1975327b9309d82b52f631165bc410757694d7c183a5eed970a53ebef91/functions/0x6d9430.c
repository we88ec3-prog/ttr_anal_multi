
void FUN_006d9430(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *in_ECX;
  char *pcVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093568e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8 = 0;
    FUN_004f3d80(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  local_8 = 0xffffffff;
  FUN_0047fdf0(&param_1);
  if (in_ECX == DAT_00fb74e4) {
    pcVar4 = "nullsound";
  }
  else {
    pcVar4 = (char *)FUN_004f6e80();
    if (pcVar4 == (char *)0x0) {
      FUN_006d9680();
      if (0xf < (uint)in_ECX[5]) {
        in_ECX = (undefined4 *)*in_ECX;
      }
      *(undefined1 *)in_ECX = 0;
      ExceptionList = local_10;
      return;
    }
  }
  iVar2 = DAT_00fb1318;
  in_ECX[7] = 0;
  if ((*(int *)(iVar2 + 0xbfd4) != 0) &&
     (iVar2 = FUN_0040f060(), *(char *)(*(int *)(iVar2 + 4) + 0x36) == '\0')) {
    pcVar3 = pcVar4;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar4,(int)pcVar3 - (int)(pcVar4 + 1));
    in_ECX[7] = 1;
    in_ECX[8] = 1;
    ExceptionList = local_10;
    return;
  }
  FUN_006d9b30(in_ECX,pcVar4,1,*(undefined2 *)(in_ECX + 0x29));
  ExceptionList = local_10;
  return;
}

