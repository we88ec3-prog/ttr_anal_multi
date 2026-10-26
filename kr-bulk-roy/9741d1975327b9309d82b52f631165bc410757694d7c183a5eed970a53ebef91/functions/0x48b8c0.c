
void FUN_0048b8c0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 ****ppppuVar4;
  int iVar5;
  char *in_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar6;
  uint uVar7;
  undefined4 ***local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917e28;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
  pcVar3 = in_ECX;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  local_14 = uVar2;
  FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
  uVar7 = 0;
  local_8 = 0;
  if (local_20 != 0) {
    do {
      ppppuVar4 = (undefined4 ****)local_30[0];
      if (local_1c < 0x10) {
        ppppuVar4 = local_30;
      }
      if (*(char *)((int)ppppuVar4 + uVar7) == '\\') {
        ppppuVar4 = (undefined4 ****)local_30[0];
        if (local_1c < 0x10) {
          ppppuVar4 = local_30;
        }
        *(undefined1 *)((int)ppppuVar4 + uVar7) = 0x2f;
      }
      else {
        ppppuVar4 = (undefined4 ****)local_30[0];
        if (local_1c < 0x10) {
          ppppuVar4 = local_30;
        }
        iVar5 = _tolower((int)*(char *)((int)ppppuVar4 + uVar7));
        *(char *)((int)ppppuVar4 + uVar7) = (char)iVar5;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < local_20);
  }
  FUN_00403040(local_30,0,0xffffffff);
  uVar6 = extraout_EDX;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0],uVar2);
    uVar6 = extraout_EDX_00;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar6,param_1);
  return;
}

