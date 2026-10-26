
void FUN_0051d450(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_a0;
  int local_9c;
  undefined4 local_94;
  undefined **local_90 [19];
  uint local_44;
  undefined4 local_34;
  uint local_30;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925deb;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  FUN_0072ee30(local_90);
  local_8 = 0;
  cVar1 = FUN_0072f110(0);
  if (cVar1 != '\0') {
    iVar3 = FUN_0072e2e0("UNIDENTIFIED_PRODUCT");
    if (iVar3 != 0) {
      iVar3 = FUN_0072e360(uVar2);
      while (iVar3 != 0) {
        iVar3 = FUN_007300a0("PRODUCT");
        if (iVar3 == 0) {
LAB_0051d57b:
          local_94 = 0;
        }
        else {
          puVar4 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          if (puVar4 == (undefined4 *)0x0) goto LAB_0051d57b;
          local_94 = FUN_008917b4(puVar4);
        }
        FUN_008438c0(&local_94);
        if ((local_9c != *(int *)(param_1 + 4)) && (iVar3 = *(int *)(local_9c + 0x10), iVar3 != 0))
        {
          iVar5 = FUN_007300a0("ORIGIN_PRODUCT");
          if (iVar5 == 0) {
LAB_0051d5df:
            local_94 = 0;
          }
          else {
            puVar4 = (undefined4 *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              puVar4 = (undefined4 *)*puVar4;
            }
            if (puVar4 == (undefined4 *)0x0) goto LAB_0051d5df;
            local_94 = FUN_008917b4(puVar4);
          }
          *(undefined4 *)(iVar3 + 0x50) = local_94;
          FUN_008438c0(&local_94);
          if (((local_a0 != *(int *)(param_1 + 4)) &&
              (iVar3 = *(int *)(local_a0 + 0x10), iVar3 != 0)) && (*(int *)(iVar3 + 100) == 0)) {
            puVar4 = (undefined4 *)FUN_00891268(0xc);
            if (puVar4 == (undefined4 *)0x0) {
              puVar4 = (undefined4 *)0x0;
            }
            else {
              puVar4[1] = 3;
              *puVar4 = ITEM::CBoolenProperty::vftable;
              puVar4[2] = 1;
            }
            *(undefined4 **)(iVar3 + 0x58 + puVar4[1] * 4) = puVar4;
          }
        }
        iVar3 = FUN_0072e3c0();
      }
      local_8 = 0xffffffff;
      local_90[0] = TiXmlDocument::vftable;
      if (0xf < local_30) {
        FUN_0089120c(local_44);
      }
      local_30 = 0xf;
      local_34 = 0;
      local_44 = local_44 & 0xffffff00;
      FUN_0072e040();
      goto LAB_0051d6a4;
    }
    FUN_006edb60("This Is Not a Unidentified Product File.");
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
LAB_0051d6a4:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

