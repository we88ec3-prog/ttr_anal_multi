
void FUN_0073b960(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int local_10;
  uint *local_c;
  int local_8;
  
  piVar8 = param_3;
  if (param_3 != (int *)0x0) {
    if (param_2 == (int *)0x0) {
      param_2 = &DAT_00f88d0c;
    }
    iVar4 = param_2[2] - *param_2;
    iVar1 = param_3[1];
    iVar7 = param_2[3] - param_2[1];
    iVar2 = param_3[2] - *param_3;
    if (param_3[2] < 0) {
      iVar2 = iVar4;
    }
    iVar6 = param_3[3] - iVar1;
    if (param_3[3] < 0) {
      iVar6 = iVar7;
    }
    param_3 = (int *)iVar4;
    if (iVar2 <= iVar4) {
      param_3 = (int *)iVar2;
    }
    if (iVar7 < iVar6) {
      iVar6 = iVar7;
    }
    piVar8[2] = *piVar8 + (int)param_3;
    piVar8[3] = iVar6 + iVar1;
    iVar1 = (**(code **)(*param_1 + 0x4c))(param_1,0,&local_10,piVar8,0);
    if (-1 < iVar1) {
      iVar1 = param_2[1];
      piVar8 = *(int **)(local_8 + 0x14);
      if (iVar1 < iVar1 + iVar6) {
        local_8 = (iVar1 + iVar6) - iVar1;
        do {
          iVar1 = *param_2;
          if (iVar1 < (int)param_3 + iVar1) {
            iVar1 = ((int)param_3 + iVar1) - iVar1;
            piVar3 = piVar8;
            puVar5 = local_c;
            do {
              *puVar5 = *piVar3 << 8 | 0xffffff;
              piVar3 = piVar3 + 1;
              puVar5 = puVar5 + 1;
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
          }
          local_c = (uint *)((int)local_c + local_10);
          piVar8 = piVar8 + 0x800;
          local_8 = local_8 + -1;
        } while (local_8 != 0);
      }
      (**(code **)(*param_1 + 0x50))(param_1,0);
    }
  }
  return;
}

