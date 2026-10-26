
/* WARNING: Type propagation algorithm not settling */

void FUN_00860e30(int param_1)

{
  undefined4 **ppuVar1;
  undefined4 **ppuVar2;
  undefined4 *******pppppppuVar3;
  undefined4 *puVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  uint *puVar7;
  undefined4 *puVar8;
  undefined4 uStack_b4;
  int *piStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 *puStack_a4;
  int iStack_a0;
  int iStack_9c;
  undefined4 *puStack_98;
  int iStack_94;
  int aiStack_90 [2];
  undefined4 *******pppppppuStack_88;
  undefined4 uStack_84;
  int iStack_80;
  undefined4 uStack_7c;
  undefined4 *puStack_78;
  uint uStack_74;
  int iStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  void *pvStack_64;
  undefined1 auStack_54 [20];
  int local_40;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00920458;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_54;
  pvStack_64 = (void *)(DAT_00d61f20 ^ (uint)&stack0xffffffa0);
  ExceptionList = &local_14;
  local_40 = param_1;
  uStack_68 = 0x860e7e;
  FUN_00781ea0();
  uStack_74 = *(uint *)(param_1 + 0x84);
  uStack_68 = 0;
  uStack_6c = 4;
  iStack_70 = in_ECX + 0x2c;
  puStack_78 = (undefined4 *)0x860e93;
  FUN_006ddcc0();
  uStack_84 = *(undefined4 *)(param_1 + 0x84);
  puStack_78 = (undefined4 *)0x0;
  uStack_7c = 4;
  iStack_80 = in_ECX + 0x28;
  pppppppuStack_88 = (undefined4 *******)0x860ea6;
  FUN_006ddcc0();
  iStack_94 = *(int *)(param_1 + 0x84);
  pppppppuStack_88 = (undefined4 *******)0x0;
  aiStack_90[1] = 4;
  aiStack_90[0] = in_ECX + 0x40;
  iStack_70 = 0;
  puStack_98 = (undefined4 *)0x860ebd;
  FUN_006ddcc0();
  puStack_a4 = *(undefined4 **)(param_1 + 0x84);
  puStack_98 = (undefined4 *)0x0;
  iStack_9c = 4;
  iStack_a0 = in_ECX + 0x48;
  uStack_a8 = 0x860ed0;
  FUN_006ddcc0();
  uStack_b4 = *(undefined4 *)(param_1 + 0x84);
  uStack_a8 = 0;
  uStack_ac = 4;
  piStack_b0 = aiStack_90;
  FUN_006ddcc0();
  iStack_9c = 0;
  if (0 < iStack_a0) {
    puVar7 = (uint *)(in_ECX + 0x30);
    do {
      puStack_98 = (undefined4 *)FUN_00891268(8);
      if (puStack_98 == (undefined4 *)0x0) {
        puStack_98 = (undefined4 *)0x0;
      }
      else {
        *puStack_98 = 0;
        puStack_98[1] = 0;
      }
      puVar8 = puStack_98;
      FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),puStack_98,4,0);
      uStack_84 = 0xf;
      pppppppuStack_88 = (undefined4 *******)0x0;
      puStack_98 = (undefined4 *)((uint)puStack_98 & 0xffffff00);
      uStack_6c = 0;
      uStack_b4 = 0;
      FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&uStack_b4,4,0);
      if (puStack_a4 != (undefined4 *)0x0) {
        if (puStack_78 < puStack_a4) {
          FUN_00429630((int)puStack_a4 - (int)puStack_78,0);
        }
        else {
          FUN_00402c80(puStack_a4,0xffffffff);
        }
        pppppppuVar3 = pppppppuStack_88;
        if (uStack_74 < 0x10) {
          pppppppuVar3 = &pppppppuStack_88;
        }
        if (puStack_a4 != (undefined4 *)0x0) {
          FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),pppppppuVar3,puStack_a4,0);
        }
      }
      if (puStack_78 != (undefined4 *)0x0) {
        pppppppuVar3 = pppppppuStack_88;
        if (uStack_74 < 0x10) {
          pppppppuVar3 = &pppppppuStack_88;
        }
        puVar4 = (undefined4 *)
                 (**(code **)(**(int **)(param_1 + 0x90) + 0x54))(aiStack_90 + 1,pppppppuVar3);
        puVar8[1] = *puVar4;
      }
      ppuVar1 = *(undefined4 ***)(in_ECX + 0x34);
      puStack_a4 = puVar8;
      if ((&puStack_a4 < ppuVar1) && (ppuVar2 = (undefined4 **)*puVar7, ppuVar2 <= &puStack_a4)) {
        if (ppuVar1 == *(undefined4 ***)(in_ECX + 0x38)) {
          uVar5 = (int)ppuVar1 - (int)ppuVar2 >> 2;
          if (0x3ffffffe < uVar5) {
LAB_0086111d:
                    /* WARNING: Subroutine does not return */
            FUN_0087db30("vector<T> too long");
          }
          uVar5 = uVar5 + 1;
          uVar6 = (int)*(undefined4 ***)(in_ECX + 0x38) - (int)ppuVar2 >> 2;
          if (uVar6 < uVar5) {
            if (0x3fffffff - (uVar6 >> 1) < uVar6) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 + (uVar6 >> 1);
            }
            if (uVar6 < uVar5) {
              uVar6 = uVar5;
            }
            FUN_00797980(uVar6);
            param_1 = aiStack_90[0];
          }
        }
        if (*(undefined4 **)(in_ECX + 0x34) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x34) =
               *(undefined4 *)(*puVar7 + ((int)&puStack_a4 - (int)ppuVar2 >> 2) * 4);
        }
      }
      else {
        if (ppuVar1 == *(undefined4 ***)(in_ECX + 0x38)) {
          uVar5 = (int)((int)ppuVar1 - *puVar7) >> 2;
          if (0x3ffffffe < uVar5) goto LAB_0086111d;
          uVar5 = uVar5 + 1;
          uVar6 = (int)((int)*(undefined4 ***)(in_ECX + 0x38) - *puVar7) >> 2;
          if (uVar6 < uVar5) {
            if (0x3fffffff - (uVar6 >> 1) < uVar6) {
              uVar6 = 0;
            }
            else {
              uVar6 = uVar6 + (uVar6 >> 1);
            }
            if (uVar6 < uVar5) {
              uVar6 = uVar5;
            }
            FUN_00797980(uVar6);
            puVar8 = puStack_98;
          }
        }
        if (*(undefined4 **)(in_ECX + 0x34) != (undefined4 *)0x0) {
          **(undefined4 **)(in_ECX + 0x34) = puVar8;
        }
      }
      *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 4;
      FUN_008613c0(*puVar7,*(int *)(iStack_94 + 0x34),
                   (int)(*(int *)(iStack_94 + 0x34) - *puVar7) >> 2,FUN_008613a0);
      if (0xf < uStack_74) {
        FUN_0089120c(pppppppuStack_88);
      }
      iStack_9c = iStack_9c + 1;
    } while (iStack_9c < iStack_a0);
  }
  ExceptionList = pvStack_64;
  uStack_a8 = 0x861117;
  __security_check_cookie(uStack_6c ^ (uint)&puStack_a4);
  return;
}

