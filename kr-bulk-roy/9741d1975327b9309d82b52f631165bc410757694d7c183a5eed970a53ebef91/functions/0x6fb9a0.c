
/* WARNING: Removing unreachable block (ram,0x006fba01) */

void FUN_006fb9a0(int param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int local_c;
  
  local_c = 0;
  do {
    iVar4 = param_2[2];
    if (iVar4 == 5) {
      iVar4 = *param_2;
      piVar2 = (int *)FUN_006f9c50();
      *(undefined1 *)(iVar4 + 6) = 0;
      if (piVar2 == &DAT_00c0bfc8) {
        if (*(int *)(param_3 + 8) == 0) {
          FUN_006f8b60(param_1,"table index is nil");
        }
        piVar2 = (int *)FUN_006f9a60(param_1,iVar4,param_3);
      }
      if ((((piVar2[2] != 0) || (*(int *)(iVar4 + 8) == 0)) ||
          ((*(byte *)(*(int *)(iVar4 + 8) + 6) & 2) != 0)) ||
         (piVar3 = (int *)FUN_006fea60(1), piVar3 == (int *)0x0)) {
        *piVar2 = *param_4;
        piVar2[1] = param_4[1];
        piVar2[2] = param_4[2];
        if (param_4[2] < 4) {
          return;
        }
        if ((*(byte *)(*param_4 + 5) & 3) == 0) {
          return;
        }
        if ((*(byte *)(iVar4 + 5) & 4) == 0) {
          return;
        }
        iVar1 = *(int *)(param_1 + 0x10);
        *(byte *)(iVar4 + 5) = *(byte *)(iVar4 + 5) & 0xfb;
        *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar1 + 0x28);
        *(int *)(iVar1 + 0x28) = iVar4;
        return;
      }
    }
    else {
      if (iVar4 == 5) {
        iVar4 = *(int *)(*param_2 + 8);
      }
      else if (iVar4 == 7) {
        iVar4 = *(int *)(*param_2 + 8);
      }
      else {
        iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0x98 + iVar4 * 4);
      }
      if (iVar4 != 0) {
        iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0xc0);
        for (piVar3 = (int *)(((1 << (*(byte *)(iVar4 + 7) & 0x1f)) - 1U & *(uint *)(iVar1 + 8)) *
                              0x20 + *(int *)(iVar4 + 0x10)); piVar3 != (int *)0x0;
            piVar3 = (int *)piVar3[7]) {
          if ((piVar3[6] == 4) && (piVar3[4] == iVar1)) goto LAB_006fbb0c;
        }
      }
      piVar3 = &DAT_00c0bfc8;
LAB_006fbb0c:
      if (piVar3[2] == 0) {
        FUN_006f8970("index");
      }
    }
    if (piVar3[2] == 6) {
      FUN_006fb7b0(param_1,piVar3,param_2);
      return;
    }
    local_c = local_c + 1;
    param_2 = piVar3;
    if (99 < local_c) {
      FUN_006f8b60(param_1,"loop in settable");
      return;
    }
  } while( true );
}

