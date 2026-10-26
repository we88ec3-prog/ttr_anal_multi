
/* WARNING: Removing unreachable block (ram,0x0071c585) */

bool FUN_0071c4a0(int **param_1)

{
  undefined1 uVar1;
  int *in_EAX;
  int *piVar2;
  int *piVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined8 uVar7;
  int *local_10;
  int local_c [2];
  
  ppiVar4 = param_1;
  FUN_0071c440();
  uVar7 = FUN_0071c440();
  uVar6 = (uint)((ulonglong)uVar7 >> 0x20);
  if ((uVar6 != 0) && ((uint)uVar7 != 0)) {
    return uVar6 < (uint)uVar7;
  }
  piVar2 = ppiVar4[1];
  param_1 = ppiVar4;
  if (piVar2 != (int *)0x0) {
    param_1 = (int **)0x0;
    param_1 = (int **)&param_1;
  }
  local_10 = (int *)in_EAX[1];
  param_1 = (int **)*param_1;
  piVar3 = in_EAX;
  if (local_10 != (int *)0x0) {
    local_c[1] = 0;
    piVar3 = local_c + 1;
  }
  piVar3 = (int *)*piVar3;
  if (piVar2 == (int *)0x0) {
LAB_0071c5ca:
    if (local_10 == (int *)0x0) goto LAB_0071c5fc;
    if (piVar2 != (int *)0x0) {
      local_10 = (int *)0x0;
      ppiVar4 = &local_10;
    }
    piVar2 = *ppiVar4;
    piVar3 = (int *)FUN_00721400();
    if ((int *)*piVar3 == piVar2) {
      return true;
    }
  }
  else {
    if (local_10 == (int *)0x0) {
      if (piVar2 != (int *)0x0) {
        if (piVar2 == (int *)0x0) {
          if (*ppiVar4 == (int *)0x0) {
            param_1 = (int **)0x0;
          }
          else {
            param_1 = (int **)(*ppiVar4)[1];
          }
          ppiVar4 = (int **)&param_1;
        }
        if (*ppiVar4 == (int *)*in_EAX) {
          return false;
        }
        puVar5 = (undefined4 *)FUN_00721400();
        param_1 = (int **)*puVar5;
        goto LAB_0071c5fc;
      }
      goto LAB_0071c5ca;
    }
    piVar2 = (int *)FUN_00721400();
    piVar3 = (int *)FUN_00721400();
    if (*piVar3 == *piVar2) {
      piVar2 = ppiVar4[1];
      while( true ) {
        if (piVar2 == (int *)0x0) {
          return false;
        }
        if (piVar2 == local_10) break;
        if (piVar2 == (int *)0x0) {
          local_c[0] = 0;
          piVar2 = local_c;
        }
        else {
          param_1 = (int **)piVar2[4];
          piVar2 = (int *)&param_1;
        }
        piVar2 = (int *)*piVar2;
      }
      return true;
    }
    piVar2 = (int *)FUN_00721400();
    param_1 = (int **)*piVar2;
  }
  puVar5 = (undefined4 *)FUN_00721400();
  piVar3 = (int *)*puVar5;
LAB_0071c5fc:
  piVar2 = (int *)param_1;
  if (param_1 == (int **)piVar3) {
    return false;
  }
  FUN_0071c2e0(piVar3);
  FUN_0071c2e0(piVar2,piVar3);
  uVar1 = FUN_0071c320(piVar2);
  return (bool)uVar1;
}

