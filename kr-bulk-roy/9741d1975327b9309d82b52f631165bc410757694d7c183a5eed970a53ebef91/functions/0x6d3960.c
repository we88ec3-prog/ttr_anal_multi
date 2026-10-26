
void FUN_006d3960(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined1 auStack_a4 [4];
  int iStack_a0;
  undefined4 uStack_9c;
  undefined **local_98 [19];
  uint local_4c;
  undefined4 uStack_3c;
  uint local_38;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009227ab;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_a4;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff50;
  ExceptionList = &local_14;
  FUN_0072ee30(local_98);
  local_c = 0;
  cVar1 = FUN_0072f110(0);
  if ((cVar1 != '\0') && (iVar3 = FUN_0072e2e0("KEYMAPEXTRA"), iVar3 != 0)) {
    piVar4 = (int *)FUN_0072e2e0(&DAT_00bf2330);
    while (piVar4 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar4 + 0x14))();
      iVar3 = iStack_a0;
      if (iVar5 != 0) {
        iVar3 = FUN_007300a0(&DAT_00bfb82c);
        if (iVar3 == 0) {
LAB_006d3ada:
          iVar5 = 0;
        }
        else {
          puVar6 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar6 = (undefined4 *)*puVar6;
          }
          if (puVar6 == (undefined4 *)0x0) goto LAB_006d3ada;
          iVar5 = FUN_008917b4(puVar6);
          iVar3 = iStack_a0;
          if ((((iVar5 == 11000) || (iVar5 == 0x2af9)) || (iVar5 == 0x2afa)) || (iVar5 == 0x2afb))
          goto LAB_006d3b0f;
        }
        iStack_a0 = iVar5;
        uVar7 = FUN_006d43f0(&DAT_00fdf414);
        FUN_0044b4a0(uVar7);
        piVar4 = (int *)FUN_0072e2e0("VALUE");
        iVar3 = iStack_a0;
        while (iStack_a0 = iVar5, piVar4 != (int *)0x0) {
          (**(code **)(*piVar4 + 0x14))();
          iVar3 = FUN_007300a0("KeyCode");
          if (iVar3 == 0) {
LAB_006d3ade:
            uStack_9c = 0;
          }
          else {
            puVar6 = (undefined4 *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              puVar6 = (undefined4 *)*puVar6;
            }
            if (puVar6 == (undefined4 *)0x0) goto LAB_006d3ade;
            uStack_9c = FUN_008917b4(puVar6);
          }
          FUN_006d43f0(&DAT_00fdf414);
          FUN_004a8680();
          piVar4 = (int *)FUN_0072e320("VALUE");
          iVar5 = iStack_a0;
          iVar3 = iStack_a0;
        }
      }
LAB_006d3b0f:
      iStack_a0 = iVar3;
      piVar4 = (int *)FUN_0072e320(&DAT_00bf2330);
    }
  }
  local_c = 0xffffffff;
  local_98[0] = TiXmlDocument::vftable;
  if (0xf < local_38) {
    FUN_0089120c(local_4c,uVar2);
  }
  local_38 = 0xf;
  uStack_3c = 0;
  local_4c = local_4c & 0xffffff00;
  FUN_0072e040();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_a4);
  return;
}

