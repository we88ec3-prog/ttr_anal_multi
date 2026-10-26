
void FUN_0086fa90(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  char ****ppppcVar3;
  int in_ECX;
  undefined4 extraout_EDX;
  char ****ppppcVar4;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 local_34;
  char ***local_30 [4];
  int local_20;
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
  local_14 = uVar2;
  if (*(int *)(in_ECX + 0x3c) != 0) {
    local_34 = 0xffffffff;
    FUN_0086d600(local_30,&local_34);
    local_8 = 0;
    param_1 = extraout_EDX;
    if (local_20 != 0) {
      ppppcVar4 = (char ****)local_30[0];
      if (local_1c < 0x10) {
        ppppcVar4 = local_30;
      }
      ppppcVar3 = ppppcVar4;
      do {
        cVar1 = *(char *)ppppcVar3;
        ppppcVar3 = (char ****)((int)ppppcVar3 + 1);
      } while (cVar1 != '\0');
      FUN_00402a70(ppppcVar4,(int)ppppcVar3 - (int)((int)ppppcVar4 + 1));
      param_1 = extraout_EDX_00;
    }
    if (0xf < local_1c) {
      FUN_0089120c(local_30[0],uVar2);
      param_1 = extraout_EDX_01;
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,param_1);
  return;
}

