
void FUN_00554fc0(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_9c [4];
  undefined **local_98 [19];
  uint local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092af8b;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_9c;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff60;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 != '\0') && (iVar3 = FUN_0072e2e0("LoadDisplay"), iVar3 != 0)) {
    iVar3 = FUN_0072e2e0("BackGround");
    if (iVar3 != 0) {
      FUN_00554b30(iVar3);
    }
    iVar3 = FUN_0072e2e0("LoadDisplayTooltip");
    if (iVar3 != 0) {
      FUN_00554e70(iVar3);
    }
  }
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c,uVar2);
  }
  local_38 = 0xf;
  local_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_9c);
  return;
}

