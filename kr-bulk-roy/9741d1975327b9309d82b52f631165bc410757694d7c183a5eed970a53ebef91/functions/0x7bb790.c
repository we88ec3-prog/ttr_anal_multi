
void FUN_007bb790(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float10 fVar6;
  int local_10;
  
  if ((in_ECX != param_1) && (puVar3 = in_ECX + 1, puVar3 != param_1)) {
    local_10 = (int)puVar3 - (int)in_ECX;
    do {
      piVar1 = (int *)*in_ECX;
      piVar2 = (int *)*puVar3;
      fVar5 = (float10)(**(code **)(*piVar2 + 8))(&stack0x00000008);
      fVar6 = (float10)(**(code **)(*piVar1 + 8))(&stack0x00000008);
      puVar4 = puVar3;
      if (fVar6 <= (float10)(double)fVar5) {
        while( true ) {
          piVar1 = (int *)puVar4[-1];
          fVar5 = (float10)(**(code **)(*piVar2 + 8))(&stack0x00000008);
          fVar6 = (float10)(**(code **)(*piVar1 + 8))(&stack0x00000008);
          if (fVar6 <= (float10)(double)fVar5) break;
          *puVar4 = puVar4[-1];
          puVar4 = puVar4 + -1;
        }
        *puVar4 = piVar2;
      }
      else {
        FID_conflict__memcpy(puVar3 + (1 - (local_10 >> 2)),in_ECX,(local_10 >> 2) * 4);
        *in_ECX = piVar2;
      }
      local_10 = local_10 + 4;
      puVar3 = puVar3 + 1;
    } while (puVar3 != param_1);
  }
  return;
}

