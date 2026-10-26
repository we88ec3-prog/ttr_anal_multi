
int FUN_008ddce0(int *param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  uVar1 = *(undefined4 *)(*param_1 + 0x1c);
  *param_2 = 0;
  local_c = 0;
  if (((((param_1[6] != 0) || (local_8 = FUN_008ddb60(), local_8 == 0)) && (param_1[2] != 0)) &&
      (piVar3 = (int *)FUN_008bc7d0(uVar1,4,0,param_1[2] + 1,0,&local_8), local_8 == 0)) &&
     ((param_3 == (int *)0x0 ||
      (local_c = FUN_008baee0(uVar1,param_1[5] + param_1[2],&local_8), local_8 == 0)))) {
    iVar2 = param_1[7];
    local_10 = 0;
    iVar4 = iVar2;
    if (param_3 != (int *)0x0) {
      iVar4 = local_c;
    }
    uVar6 = 1;
    *piVar3 = iVar4;
    uVar5 = 0;
    if (param_1[2] != 0) {
      do {
        uVar7 = *(int *)(param_1[6] + uVar6 * 4) - 1;
        uVar8 = uVar5;
        if ((uVar5 <= uVar7) && (uVar8 = uVar7, (uint)param_1[5] < uVar7)) {
          uVar8 = param_1[5];
        }
        if (param_3 == (int *)0x0) {
          piVar3[uVar6] = uVar8 + iVar2;
        }
        else {
          iVar4 = local_c + uVar8 + local_10;
          piVar3[uVar6] = iVar4;
          if (uVar8 != uVar5) {
            FID_conflict__memcpy
                      ((void *)piVar3[uVar6 - 1],(void *)(uVar5 + iVar2),iVar4 - piVar3[uVar6 - 1]);
            *(undefined1 *)piVar3[uVar6] = 0;
            piVar3[uVar6] = piVar3[uVar6] + 1;
            local_10 = local_10 + 1;
          }
        }
        uVar6 = uVar6 + 1;
        uVar5 = uVar8;
      } while (uVar6 <= (uint)param_1[2]);
    }
    *param_2 = piVar3;
    if (param_3 != (int *)0x0) {
      *param_3 = local_c;
    }
  }
  return local_8;
}

