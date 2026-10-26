
int FUN_007086f0(int param_1,FILE *param_2,int param_3)

{
  char cVar1;
  double *pdVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  bool bVar8;
  int local_14;
  char *local_10;
  int local_c;
  
  local_c = (*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4) + -1;
  FUN_0089a229(param_2);
  if (local_c == 0) {
    iVar3 = FUN_007083f0(param_1);
    local_14 = param_3 + 1;
  }
  else {
    iVar3 = FUN_006f5170();
    if (iVar3 == 0) {
      FUN_006f5f30(param_1,"stack overflow (%s)","too many arguments");
    }
    iVar3 = 1;
    local_14 = param_3;
    do {
      local_c = local_c + -1;
      bVar8 = iVar3 == 0;
      iVar3 = 0;
      if (bVar8) break;
      puVar7 = (undefined4 *)FUN_006f50f0();
      if ((puVar7 == &DAT_00c0bfc8) || (puVar7[2] != 3)) {
        piVar5 = (int *)FUN_006f50f0();
        if (piVar5[2] == 4) {
LAB_0070885f:
          local_10 = (char *)(*piVar5 + 0x10);
          if ((local_10 == (char *)0x0) || (*local_10 != '*')) goto LAB_0070886f;
        }
        else {
          iVar3 = FUN_006fb5d0();
          if (iVar3 != 0) {
            if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <=
                *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
              FUN_006fb3a0();
            }
            piVar5 = (int *)FUN_006f50f0();
            goto LAB_0070885f;
          }
          local_10 = (char *)0x0;
LAB_0070886f:
          FUN_006f5da0(local_14);
        }
        cVar1 = local_10[1];
        if (cVar1 == 'a') {
          FUN_00708580(param_1,0xffffffff);
          iVar3 = 1;
        }
        else if (cVar1 == 'l') {
          iVar3 = FUN_007083f0(param_1);
        }
        else {
          if (cVar1 != 'n') {
            iVar3 = FUN_006f5da0(local_14);
            return iVar3;
          }
          iVar3 = FUN_00708350();
        }
      }
      else {
        iVar3 = FUN_006f5370();
        if (iVar3 == 0) {
          iVar3 = FUN_00708390();
        }
        else {
          iVar3 = FUN_00708580(param_1,iVar3);
        }
      }
      local_14 = local_14 + 1;
    } while (local_c != 0);
  }
  iVar4 = _ferror(param_2);
  if (iVar4 == 0) {
    if (iVar3 == 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    }
    return local_14 - param_3;
  }
  piVar5 = __errno();
  iVar3 = *piVar5;
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  uVar6 = FUN_00898466(iVar3);
  FUN_006f5580(param_1,&DAT_00bfc638,uVar6);
  pdVar2 = *(double **)(param_1 + 8);
  *(undefined4 *)(pdVar2 + 1) = 3;
  *pdVar2 = (double)iVar3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 3;
}

