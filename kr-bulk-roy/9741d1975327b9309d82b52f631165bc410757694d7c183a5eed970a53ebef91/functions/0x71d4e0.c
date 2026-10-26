
void FUN_0071d4e0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float10 fVar4;
  float10 fVar5;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = (undefined4 *)(*(int *)(param_1 + 4) + param_2 * 8);
  param_2 = ((int)*(undefined4 **)(param_1 + 8) - *(int *)(param_1 + 4) >> 3) - param_2;
  local_8 = 1;
  puVar3 = puVar2;
  if (puVar2 == *(undefined4 **)(param_1 + 8)) {
    *(undefined4 **)(param_1 + 8) = puVar2;
    return;
  }
  do {
    local_18 = *puVar2;
    local_14 = puVar2[1];
    local_10 = local_8;
    local_c = param_2;
    if (*(char *)(param_3 + 1) == '\x02') {
      fVar4 = (float10)FUN_0071de00(&local_18,param_4);
      fVar5 = (float10)local_8;
      if (local_8 < 0) {
        fVar5 = fVar5 + (float10)4294967296.0;
      }
      if (fVar5 == fVar4) {
        *puVar3 = *puVar2;
        puVar3[1] = puVar2[1];
LAB_0071d574:
        puVar3 = puVar3 + 2;
      }
    }
    else {
      cVar1 = FUN_0071d8f0(&local_18,param_4);
      if (cVar1 != '\0') {
        *puVar3 = *puVar2;
        puVar3[1] = puVar2[1];
        goto LAB_0071d574;
      }
    }
    local_8 = local_8 + 1;
    puVar2 = puVar2 + 2;
    if (puVar2 == *(undefined4 **)(param_1 + 8)) {
      *(undefined4 **)(param_1 + 8) = puVar3;
      return;
    }
  } while( true );
}

