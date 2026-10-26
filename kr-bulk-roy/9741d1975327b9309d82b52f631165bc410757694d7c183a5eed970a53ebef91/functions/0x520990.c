
void FUN_00520990(undefined4 param_1)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  char *pcVar10;
  int in_ECX;
  undefined1 local_8;
  
  iVar7 = FUN_007300a0("target_level");
  if (iVar7 != 0) {
    puVar8 = (undefined4 *)(iVar7 + 0x30);
    if (0xf < *(uint *)(iVar7 + 0x44)) {
      puVar8 = (undefined4 *)*puVar8;
    }
    if (puVar8 != (undefined4 *)0x0) {
      uVar6 = FUN_008917b4(puVar8);
      goto LAB_005209cb;
    }
  }
  uVar6 = 0;
LAB_005209cb:
  *(undefined1 *)(in_ECX + 0x1c) = uVar6;
  iVar7 = FUN_0072e360();
  if (iVar7 != 0) {
    do {
      for (iVar2 = *(int *)(iVar7 + 0x94); iVar2 != iVar7 + 0x44; iVar2 = *(int *)(iVar2 + 0x50)) {
        pcVar10 = (char *)(iVar2 + 0x14);
        if (0xf < *(uint *)(iVar2 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar9 = __stricmp(pcVar10,"class");
        if (iVar9 == 0) {
          if (iVar2 != 0) {
            puVar8 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar8 = (undefined4 *)*puVar8;
            }
            if (puVar8 != (undefined4 *)0x0) {
              local_8 = FUN_008917b4(puVar8);
              goto LAB_00520a32;
            }
          }
          break;
        }
      }
      local_8 = 0;
LAB_00520a32:
      for (iVar2 = *(int *)(iVar7 + 0x94); iVar2 != iVar7 + 0x44; iVar2 = *(int *)(iVar2 + 0x50)) {
        pcVar10 = (char *)(iVar2 + 0x14);
        if (0xf < *(uint *)(iVar2 + 0x28)) {
          pcVar10 = *(char **)pcVar10;
        }
        iVar9 = __stricmp(pcVar10,"grade");
        if (iVar9 == 0) {
          if (iVar2 != 0) {
            puVar8 = (undefined4 *)(iVar2 + 0x30);
            if (0xf < *(uint *)(iVar2 + 0x44)) {
              puVar8 = (undefined4 *)*puVar8;
            }
            if (puVar8 != (undefined4 *)0x0) {
              uVar6 = FUN_008917b4(puVar8);
              goto LAB_00520a66;
            }
          }
          break;
        }
      }
      uVar6 = 0;
LAB_00520a66:
      param_1._2_1_ = local_8;
      uVar3 = *(uint *)(in_ECX + 0x10);
      param_1._3_1_ = uVar6;
      if ((int)&param_1 + 2U < uVar3) {
        uVar4 = *(uint *)(in_ECX + 0xc);
        if ((int)&param_1 + 2U < uVar4) goto LAB_00520b03;
        if (uVar3 == *(uint *)(in_ECX + 0x14)) {
          FUN_005234e0();
        }
        puVar1 = (undefined1 *)
                 (*(uint *)(in_ECX + 0xc) + ((int)(((int)&param_1 + 2U) - uVar4) >> 1) * 2);
        puVar5 = *(undefined1 **)(in_ECX + 0x10);
        if (puVar5 != (undefined1 *)0x0) {
          *puVar5 = *puVar1;
          puVar5[1] = puVar1[1];
        }
      }
      else {
LAB_00520b03:
        if (uVar3 == *(uint *)(in_ECX + 0x14)) {
          FUN_005234e0();
        }
        puVar1 = *(undefined1 **)(in_ECX + 0x10);
        if (puVar1 != (undefined1 *)0x0) {
          *puVar1 = local_8;
          puVar1[1] = uVar6;
        }
      }
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 2;
      iVar7 = FUN_0072e3c0();
    } while (iVar7 != 0);
  }
  return;
}

