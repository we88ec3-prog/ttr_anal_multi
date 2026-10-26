
void FUN_005112a0(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined **local_8c [19];
  uint local_40;
  undefined4 local_30;
  uint local_2c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009253fb;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_0072ed80(local_8c);
  local_8 = 0;
  FUN_0072f110(0);
  iVar3 = FUN_0072e2e0("BUFF_PROHIBIT");
  if (iVar3 != 0) {
    iVar3 = FUN_0072e360(uVar2);
    while (iVar3 != 0) {
      iVar3 = FUN_007300a0(&DAT_00bfb82c);
      if (iVar3 != 0) {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 != (undefined4 *)0x0) {
          FUN_008917b4(puVar4);
        }
      }
      iVar3 = FUN_007300a0(&DAT_00bfb800);
      if (iVar3 == 0) {
LAB_00511374:
        uVar1 = 0;
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if (puVar4 == (undefined4 *)0x0) goto LAB_00511374;
        uVar1 = FUN_008917b4(puVar4);
      }
      puVar5 = (undefined1 *)FUN_00511400();
      *puVar5 = uVar1;
      iVar3 = FUN_0072e3c0();
    }
  }
  local_8 = 0xffffffff;
  local_8c[0] = TiXmlDocument::vftable;
  if (0xf < local_2c) {
    FUN_0089120c(local_40);
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

