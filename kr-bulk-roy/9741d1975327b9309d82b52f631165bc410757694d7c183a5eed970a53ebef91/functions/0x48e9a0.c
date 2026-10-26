
/* WARNING: Removing unreachable block (ram,0x0048ea57) */
/* WARNING: Removing unreachable block (ram,0x0048ea77) */
/* WARNING: Removing unreachable block (ram,0x0048ea0e) */
/* WARNING: Removing unreachable block (ram,0x0048ea10) */
/* WARNING: Removing unreachable block (ram,0x0048ea30) */

void FUN_0048e9a0(void)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  int in_ECX;
  uint uVar10;
  undefined4 uVar11;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 *puVar12;
  int *piStack_70;
  int iStack_6c;
  int iStack_68;
  uint *puStack_64;
  undefined4 auStack_60 [2];
  undefined4 uStack_4c;
  int local_48;
  undefined4 uStack_44;
  undefined1 auStack_34 [4];
  uint uStack_30;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&uStack_4c;
  auStack_60[1] = 0x48e9be;
  iVar5 = FUN_006dfca0();
  auStack_60[1] = 0x48e9c9;
  local_48 = iVar5;
  puStack_64 = (uint *)FUN_006dfb80();
  auStack_60[0] = *(undefined4 *)(iVar5 + 4);
  auStack_60[1] = 0x16;
  iStack_68 = 0x48e9d7;
  (**(code **)(*puStack_64 + 0x18))();
  iStack_68 = 0x48e9e0;
  piStack_70 = (int *)FUN_006dfb80();
  iStack_6c = *(int *)(iVar5 + 4);
  iStack_68 = 0x17;
  auStack_60[1] = (**(code **)(*piStack_70 + 0x18))();
  if (*(int *)(in_ECX + 0xbfec) != *(int *)(in_ECX + 0xbff0)) {
    *(int *)(in_ECX + 0xbff0) = *(int *)(in_ECX + 0xbfec);
  }
  if (*(int *)(in_ECX + 0xbffc) != *(int *)(in_ECX + 0xc000)) {
    *(int *)(in_ECX + 0xc000) = *(int *)(in_ECX + 0xbffc);
  }
  piVar6 = (int *)FUN_006dfb80();
  (**(code **)(*piVar6 + 0x20))(piVar6,*(undefined4 *)(iVar5 + 4),auStack_34);
  iVar5 = 0;
  if (0 < (int)piStack_70) {
    do {
      if (DAT_00fba7cc == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)FUN_00891268(0x1380);
        if (puVar7 == (undefined4 *)0x0) {
          DAT_00fba7cc = (undefined4 *)0x0;
        }
        else {
          *(undefined8 *)(puVar7 + 0x4d4) = 0;
          *(undefined8 *)(puVar7 + 0x4d6) = 0;
          puVar7[0x4dc] = 1;
          puVar7[0x4dd] = 1;
          *(undefined8 *)(puVar7 + 0x4da) = 0x3fa1111111111111;
          puVar7[0x4de] = 0;
          puVar7[0x4d8] = 0x1e;
          FUN_006df660();
          DAT_00fba7cc = puVar7;
        }
      }
      puVar7 = DAT_00fba7cc;
      if (DAT_00d63d09 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      piVar6 = (int *)*puVar7;
      if (DAT_00d63d09 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      (**(code **)(*piVar6 + 0x1c))(piVar6,*(undefined4 *)(iStack_6c + 4),0x16,iVar5,auStack_60);
      iVar8 = FUN_0048e8f0();
      if (iVar8 != 0) {
        FUN_006edd00("Available Mode: %d x %d x 32 @ %d hz",auStack_60[0],auStack_60[1],
                     in_ECX + 0xbffc);
        puVar7 = *(undefined4 **)(in_ECX + 0xbff0);
        if (auStack_60 < puVar7) {
          puVar12 = *(undefined4 **)(in_ECX + 0xbfec);
          if (auStack_60 < puVar12) goto LAB_0048ebc7;
          if (puVar7 == *(undefined4 **)(in_ECX + 0xbff4)) {
            FUN_0053ec00();
          }
          puVar7 = *(undefined4 **)(in_ECX + 0xbff0);
          puVar12 = (undefined4 *)
                    (((int)auStack_60 - (int)puVar12 & 0xfffffff0U) + *(uint *)(in_ECX + 0xbfec));
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = *puVar12;
            puVar7[1] = puVar12[1];
            puVar7[2] = puVar12[2];
            uVar11 = puVar12[3];
            goto LAB_0048ebf2;
          }
        }
        else {
LAB_0048ebc7:
          if (puVar7 == *(undefined4 **)(in_ECX + 0xbff4)) {
            FUN_0053ec00();
          }
          puVar7 = *(undefined4 **)(in_ECX + 0xbff0);
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = auStack_60[0];
            puVar7[1] = auStack_60[1];
            puVar7[2] = in_ECX + 0xbffc;
            uVar11 = unaff_ESI;
LAB_0048ebf2:
            puVar7[3] = uVar11;
          }
        }
        *(int *)(in_ECX + 0xbff0) = *(int *)(in_ECX + 0xbff0) + 0x10;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)piStack_70);
  }
  piStack_70 = (int *)0x0;
  if (0 < iStack_68) {
    do {
      piVar6 = piStack_70;
      if (DAT_00fba7cc == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)FUN_00891268(0x1380);
        if (puVar7 == (undefined4 *)0x0) {
          DAT_00fba7cc = (undefined4 *)0x0;
        }
        else {
          *(undefined8 *)(puVar7 + 0x4d4) = 0;
          *(undefined8 *)(puVar7 + 0x4d6) = 0;
          puVar7[0x4dc] = 1;
          puVar7[0x4dd] = 1;
          *(undefined8 *)(puVar7 + 0x4da) = 0x3fa1111111111111;
          puVar7[0x4de] = 0;
          puVar7[0x4d8] = 0x1e;
          FUN_006df660();
          DAT_00fba7cc = puVar7;
        }
      }
      puVar7 = DAT_00fba7cc;
      if (DAT_00d63d09 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      piVar1 = (int *)*puVar7;
      if (DAT_00d63d09 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      (**(code **)(*piVar1 + 0x1c))
                (piVar1,*(undefined4 *)(iStack_6c + 4),0x17,piVar6,&stack0xffffffb0);
      iVar5 = FUN_0048e8f0();
      if (iVar5 != 0) {
        FUN_006edd00("Available Mode: %d x %d x 16 @ %d hz",unaff_EBX,uStack_4c,local_48);
        puVar4 = puStack_64;
        puVar2 = (undefined1 *)puStack_64[1];
        if ((&stack0xffffffb0 < puVar2) &&
           (puVar3 = (undefined1 *)*puStack_64, puVar3 <= &stack0xffffffb0)) {
          if (puVar2 == (undefined1 *)puStack_64[2]) {
            uVar9 = (int)puVar2 - (int)puVar3 >> 4;
            if (0xffffffe < uVar9) {
LAB_0048edfe:
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar9 = uVar9 + 1;
            uVar10 = (int)puStack_64[2] - (int)puVar3 >> 4;
            if (uVar10 < uVar9) {
              if (0xfffffff - (uVar10 >> 1) < uVar10) {
                uVar10 = 0;
              }
              else {
                uVar10 = uVar10 + (uVar10 >> 1);
              }
              if (uVar10 < uVar9) {
                uVar10 = uVar9;
              }
              FUN_00531860(uVar10);
              piVar6 = piStack_70;
            }
          }
          puVar7 = (undefined4 *)puVar4[1];
          puVar12 = (undefined4 *)(((int)&stack0xffffffb0 - (int)puVar3 & 0xfffffff0U) + *puVar4);
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = *puVar12;
            puVar7[1] = puVar12[1];
            puVar7[2] = puVar12[2];
            uVar11 = puVar12[3];
LAB_0048edd6:
            puVar7[3] = uVar11;
          }
        }
        else {
          if (puVar2 == (undefined1 *)puStack_64[2]) {
            uVar9 = (int)((int)puVar2 - *puStack_64) >> 4;
            if (0xffffffe < uVar9) goto LAB_0048edfe;
            uVar9 = uVar9 + 1;
            uVar10 = (int)((int)puStack_64[2] - *puStack_64) >> 4;
            if (uVar10 < uVar9) {
              if (0xfffffff - (uVar10 >> 1) < uVar10) {
                uVar10 = 0;
              }
              else {
                uVar10 = uVar10 + (uVar10 >> 1);
              }
              if (uVar10 < uVar9) {
                uVar10 = uVar9;
              }
              FUN_00531860(uVar10);
            }
          }
          puVar7 = (undefined4 *)puVar4[1];
          if (puVar7 != (undefined4 *)0x0) {
            *puVar7 = unaff_EBX;
            puVar7[1] = uStack_4c;
            puVar7[2] = local_48;
            uVar11 = uStack_44;
            goto LAB_0048edd6;
          }
        }
        puVar4[1] = puVar4[1] + 0x10;
      }
      piStack_70 = (int *)((int)piVar6 + 1);
    } while ((int)piStack_70 < iStack_68);
  }
  __security_check_cookie(uStack_30 ^ (uint)&piStack_70);
  return;
}

