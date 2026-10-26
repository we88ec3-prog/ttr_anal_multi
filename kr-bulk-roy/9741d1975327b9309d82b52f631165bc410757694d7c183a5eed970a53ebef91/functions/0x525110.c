
void FUN_00525110(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined **local_90 [17];
  char local_4c;
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009262fb;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar1;
  FUN_0072ee30(local_90);
  local_8 = 0;
  FUN_0072f110(0);
  if (local_4c == '\0') {
    piVar2 = (int *)FUN_0072e2e0("TALKFACETABLE");
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x14))(uVar1);
      iVar3 = FUN_007300a0(&PTR_DAT_00c0eca8);
      if (iVar3 == 0) {
LAB_00525236:
        uVar5 = (**(code **)(*piVar2 + 0x14))();
        FUN_005252f0(param_1,uVar5);
      }
      else {
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if ((puVar4 == (undefined4 *)0x0) || (iVar3 = FUN_008917b4(puVar4), iVar3 == 1))
        goto LAB_00525236;
        (**(code **)(*piVar2 + 0x14))();
        iVar3 = FUN_007300a0(&PTR_DAT_00c0eca8);
        if (iVar3 == 0) {
LAB_005252b3:
          local_8 = 0xffffffff;
          FUN_00407fb0();
          goto LAB_005252ca;
        }
        puVar4 = (undefined4 *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        if ((puVar4 == (undefined4 *)0x0) || (iVar3 = FUN_008917b4(puVar4), iVar3 != 2))
        goto LAB_005252b3;
        (**(code **)(*piVar2 + 0x14))();
        FUN_00525840(param_1);
      }
      local_8 = 0xffffffff;
      FUN_00407fb0();
      goto LAB_005252ca;
    }
    FUN_006edb60("Not TALKFACETABLE File");
  }
  local_90[0] = TiXmlDocument::vftable;
  local_8 = 0xffffffff;
  if (0xf < local_30) {
    local_8 = 0xffffffff;
    local_90[0] = TiXmlDocument::vftable;
    FUN_0089120c(local_44);
  }
  local_30 = 0xf;
  local_34 = 0;
  local_44 = local_44 & 0xffffff00;
  FUN_0072e040();
LAB_005252ca:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

