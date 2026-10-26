
/* WARNING: Removing unreachable block (ram,0x0084d417) */
/* WARNING: Removing unreachable block (ram,0x0084d42e) */

undefined4 FUN_0084d260(int param_1)

{
  void *_Dst;
  void *pvVar1;
  void *_Src;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint in_ECX;
  uint unaff_ESI;
  int *piVar7;
  uint unaff_EDI;
  undefined4 *puVar8;
  char *pcStack_7c;
  undefined4 uStack_78;
  undefined **ppuStack_74;
  int local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0091e835;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  local_3c = in_ECX;
  FUN_00781ea0();
  FUN_0084d940();
  pvVar1 = *(void **)(param_1 + 0x84);
  local_38 = 0;
  local_40 = 0;
  FUN_006ddcc0();
  if (unaff_EDI != 0) {
    FUN_00850230();
    ppuStack_74 = *(undefined ***)(param_1 + 0x84);
    uStack_78 = 0x84d2ef;
    FUN_006ddcc0();
    local_3c = 0;
    if (unaff_EDI != 0) {
      local_44 = 0;
      do {
        piVar7 = (int *)(*(int *)(unaff_ESI + 0x48) + local_44);
        _Src = (void *)piVar7[1];
        uVar3 = (int)_Src - *piVar7 >> 2;
        if (uVar2 < uVar3) {
          _Dst = (void *)(*piVar7 + uVar2 * 4);
          if (_Dst != _Src) {
            ppuStack_74 = (undefined **)0x84d348;
            FID_conflict__memcpy(_Dst,_Src,0);
            piVar7[1] = (int)_Dst;
          }
        }
        else if (uVar3 < uVar2) {
          FUN_006d6240();
          puVar8 = (undefined4 *)piVar7[1];
          iVar4 = uVar2 - ((int)puVar8 - *piVar7 >> 2);
          if (iVar4 != 0) {
            for (; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar8 = 0;
              puVar8 = puVar8 + 1;
            }
          }
          piVar7[1] = piVar7[1] + (uVar2 - (piVar7[1] - *piVar7 >> 2)) * 4;
        }
        uVar3 = uVar2;
        if (0 < (int)uVar2) {
          do {
            ppuStack_74 = *(undefined ***)(param_1 + 0x84);
            uStack_78 = 0x84d3b4;
            FUN_006ddcc0();
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
        }
        ppuStack_74 = *(undefined ***)(param_1 + 0x84);
        uStack_78 = 0x84d3d9;
        FUN_006ddcc0();
        local_3c = local_3c + 1;
        local_44 = local_44 + 0x18;
        in_ECX = unaff_ESI;
      } while (local_3c < unaff_EDI);
    }
  }
  ppuStack_74 = *(undefined ***)(param_1 + 0x84);
  uStack_78 = 0x84d40f;
  FUN_006ddcc0();
  uStack_78 = 0;
  pcStack_7c = (char *)0x4;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&stack0xffffffb0);
  if (&local_40 != (undefined4 *)0x0) {
    FUN_00850490();
    iVar4 = (int)&local_40 * 0x14;
    if (iVar4 != 0) {
      FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),*(undefined4 *)(in_ECX + 0x58),iVar4,0);
    }
  }
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),(undefined4 *)(in_ECX + 0x3c),4,0);
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),&stack0xffffff98,4,0);
  iVar4 = FUN_00891268(0x10);
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    *(undefined4 *)(iVar4 + 8) = 0;
    iVar5 = FUN_00891268(0x24);
    if (iVar5 == 0) {
      pcStack_7c = (char *)0x0;
      std::exception::exception((exception *)&ppuStack_74,&pcStack_7c);
      ppuStack_74 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&ppuStack_74,&DAT_00c857a8);
    }
    *(int *)(iVar4 + 4) = iVar5;
    *(int *)iVar5 = iVar5;
    *(int *)(*(int *)(iVar4 + 4) + 4) = *(int *)(iVar4 + 4);
    *(int *)(*(int *)(iVar4 + 4) + 8) = *(int *)(iVar4 + 4);
    *(undefined1 *)(*(int *)(iVar4 + 4) + 0x20) = 1;
    *(undefined1 *)(*(int *)(iVar4 + 4) + 0x21) = 1;
    FUN_00856f90(iVar4);
  }
  *(int *)(in_ECX + 0x40) = iVar4;
  iVar4 = FUN_00857390(iVar4,param_1);
  if (iVar4 == 0) {
    pcVar6 = *(char **)(in_ECX + 0x40);
    pcStack_7c = pcVar6;
    if (pcVar6 != (char *)0x0) {
      FUN_00856f90(pcVar6);
      FUN_006d7120(**(undefined4 **)(pcVar6 + 4),*(undefined4 **)(pcVar6 + 4));
      FUN_0089120c(*(undefined4 *)(pcVar6 + 4));
      FUN_0089120c(pcVar6);
    }
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  pcVar6 = (char *)FUN_00891268(0x20);
  pcStack_7c = pcVar6;
  if (pcVar6 == (char *)0x0) {
    pcVar6 = (char *)0x0;
  }
  else {
    pcVar6[0] = '\0';
    pcVar6[1] = '\0';
    pcVar6[2] = '\0';
    pcVar6[3] = '\0';
    pcVar6[4] = '\0';
    pcVar6[5] = '\0';
    pcVar6[6] = '\0';
    pcVar6[7] = '\0';
    pcVar6[8] = '\0';
    pcVar6[9] = '\0';
    pcVar6[10] = '\0';
    pcVar6[0xb] = '\0';
    pcVar6[0x10] = '\0';
    pcVar6[0x11] = '\0';
    pcVar6[0x12] = '\0';
    pcVar6[0x13] = '\0';
    pcVar6[0x14] = '\0';
    pcVar6[0x15] = '\0';
    pcVar6[0x16] = '\0';
    pcVar6[0x17] = '\0';
    pcVar6[0x18] = '\0';
    pcVar6[0x19] = '\0';
    pcVar6[0x1a] = '\0';
    pcVar6[0x1b] = '\0';
    FUN_00857f80();
  }
  *(char **)(in_ECX + 0x44) = pcVar6;
  iVar4 = FUN_00857d80(pcVar6,param_1);
  if (iVar4 == 0) {
    iVar4 = *(int *)(in_ECX + 0x44);
    if (iVar4 != 0) {
      FUN_00857730(iVar4);
      FUN_0089120c(iVar4);
    }
    *(undefined4 *)(in_ECX + 0x44) = 0;
  }
  ExceptionList = pvVar1;
  return 1;
}

