
void FUN_0057fde0(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *in_ECX;
  char *unaff_EDI;
  undefined1 local_3c [4];
  undefined4 local_38;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938548;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_38 = param_2;
  if (in_ECX != (int *)0x0) {
    (**(code **)(*in_ECX + 4))();
    (**(code **)(*in_ECX + 8))();
  }
  iVar2 = FUN_007cdcc0(*(undefined4 *)(param_1 + 4),unaff_EDI,local_38,in_ECX);
  if (iVar2 != 0) {
    if (in_ECX != (int *)0x0) {
      (**(code **)(*in_ECX + 4))();
      (**(code **)(*in_ECX + 8))();
    }
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = local_34[0] & 0xffffff00;
    pcVar3 = unaff_EDI;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(unaff_EDI,(int)pcVar3 - (int)(unaff_EDI + 1));
    local_8 = 0;
    uVar4 = FUN_0077e100(local_34);
    FUN_00552980(param_1 + 0x28,local_3c,uVar4);
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

