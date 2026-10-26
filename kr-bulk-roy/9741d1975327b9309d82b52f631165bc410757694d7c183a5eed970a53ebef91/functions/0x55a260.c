
void FUN_0055a260(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  float *pfVar4;
  float10 fVar5;
  float local_14;
  float local_10;
  float local_c;
  int local_8;
  
  puVar2 = param_1;
  param_1 = (undefined4 *)*param_1;
  iVar3 = FUN_0040f060();
  FUN_0082ef00(&param_1);
  if ((local_8 == *(int *)(iVar3 + 0xc)) ||
     (piVar1 = *(int **)(local_8 + 0x10), piVar1 == (int *)0x0)) {
    puVar2[3] = 0;
  }
  else {
    puVar2[3] = 1;
    pfVar4 = (float *)(**(code **)(*piVar1 + 0x4c))();
    local_14 = *pfVar4;
    local_10 = pfVar4[1];
    local_c = pfVar4[2];
    if ((((float)puVar2[0xf] != local_14) || ((float)puVar2[0x10] != local_10)) ||
       ((float)puVar2[0x11] != local_c)) {
      if ((piVar1[0x57] == 0) || (piVar1[0xdc] == 0)) {
        param_1 = (undefined4 *)0x0;
      }
      else {
        fVar5 = (float10)FUN_007a7100();
        param_1 = (undefined4 *)(float)fVar5;
      }
      local_c = (float)param_1 + 3.3 + local_c;
      FUN_0055a180(&local_14);
      return;
    }
  }
  return;
}

