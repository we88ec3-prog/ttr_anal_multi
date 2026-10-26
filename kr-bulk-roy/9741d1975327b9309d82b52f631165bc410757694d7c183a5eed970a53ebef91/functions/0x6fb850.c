
void FUN_006fb850(int param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int local_c;
  
  local_c = 0;
  do {
    iVar4 = param_2[2];
    if (iVar4 == 5) {
      iVar4 = *param_2;
      puVar2 = (undefined4 *)FUN_006f9c50();
      if ((((puVar2[2] != 0) || (*(int *)(iVar4 + 8) == 0)) ||
          ((*(byte *)(*(int *)(iVar4 + 8) + 6) & 1) != 0)) ||
         (piVar3 = (int *)FUN_006fea60(0), piVar3 == (int *)0x0)) {
        *param_4 = *puVar2;
        param_4[1] = puVar2[1];
        param_4[2] = puVar2[2];
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
        iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0xbc);
        for (piVar3 = (int *)(((1 << (*(byte *)(iVar4 + 7) & 0x1f)) - 1U & *(uint *)(iVar1 + 8)) *
                              0x20 + *(int *)(iVar4 + 0x10)); piVar3 != (int *)0x0;
            piVar3 = (int *)piVar3[7]) {
          if ((piVar3[6] == 4) && (piVar3[4] == iVar1)) goto LAB_006fb92c;
        }
      }
      piVar3 = &DAT_00c0bfc8;
LAB_006fb92c:
      if (piVar3[2] == 0) {
        FUN_006f8970("index");
      }
    }
    if (piVar3[2] == 6) {
      FUN_006fb700(param_1,param_4,piVar3,param_2,param_3);
      return;
    }
    local_c = local_c + 1;
    param_2 = piVar3;
    if (99 < local_c) {
      FUN_006f8b60(param_1,"loop in gettable");
      return;
    }
  } while( true );
}

