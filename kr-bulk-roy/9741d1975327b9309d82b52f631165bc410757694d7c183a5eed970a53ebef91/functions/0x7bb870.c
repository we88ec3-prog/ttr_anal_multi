
void FUN_007bb870(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  float10 fVar3;
  float10 fVar4;
  
  piVar1 = (int *)*unaff_EDI;
  fVar3 = (float10)(**(code **)(*(int *)*unaff_ESI + 8))(&stack0x00000008);
  fVar4 = (float10)(**(code **)(*piVar1 + 8))(&stack0x00000008);
  if ((float10)(double)fVar3 < fVar4) {
    uVar2 = *unaff_ESI;
    *unaff_ESI = *unaff_EDI;
    *unaff_EDI = uVar2;
  }
  piVar1 = (int *)*unaff_ESI;
  fVar3 = (float10)(**(code **)(*(int *)*param_1 + 8))(&stack0x00000008);
  fVar4 = (float10)(**(code **)(*piVar1 + 8))(&stack0x00000008);
  if ((float10)(double)fVar3 < fVar4) {
    uVar2 = *param_1;
    *param_1 = *unaff_ESI;
    *unaff_ESI = uVar2;
  }
  piVar1 = (int *)*unaff_EDI;
  fVar3 = (float10)(**(code **)(*(int *)*unaff_ESI + 8))(&stack0x00000008);
  fVar4 = (float10)(**(code **)(*piVar1 + 8))(&stack0x00000008);
  if ((float10)(double)fVar3 < fVar4) {
    uVar2 = *unaff_ESI;
    *unaff_ESI = *unaff_EDI;
    *unaff_EDI = uVar2;
  }
  return;
}

