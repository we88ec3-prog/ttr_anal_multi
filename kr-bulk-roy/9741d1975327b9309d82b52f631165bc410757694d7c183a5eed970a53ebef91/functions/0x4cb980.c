
void FUN_004cb980(float param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  float fVar5;
  float fVar6;
  float local_c;
  
  piVar2 = *(int **)(in_ECX + 4);
  if ((piVar2[0x57] == 0) || (piVar2[0xdc] == 0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(piVar2[0x57] + 0x11c);
  }
  if ((piVar2[0x57] == 0) || (piVar2[0xdc] == 0)) {
    fVar5 = 0.0;
  }
  else {
    fVar5 = *(float *)(piVar2[0x57] + 0xb4);
  }
  if ((piVar2[0xe3] == 0x10) && (iVar3 != 0)) {
    (**(code **)(*piVar2 + 0x68))(0xf,0x3f800000);
  }
  iVar3 = *(int *)(in_ECX + 4);
  fVar1 = *(float *)(iVar3 + 0x398);
  if (((*(int *)(iVar3 + 0x15c) == 0) || (*(int *)(iVar3 + 0x370) == 0)) ||
     (piVar2 = (int *)FUN_007a7800(*(undefined4 *)(iVar3 + 0x38c)), piVar2 == (int *)0x0)) {
    local_c = 30.0;
  }
  else {
    fVar4 = (float10)(**(code **)(*piVar2 + 0x10))();
    local_c = (float)fVar4;
  }
  iVar3 = *(int *)(in_ECX + 4);
  piVar2 = (int *)FUN_007a7800(*(undefined4 *)(iVar3 + 0x38c));
  if (piVar2 == (int *)0x0) {
    iVar3 = *(int *)(iVar3 + 0x38c);
  }
  else {
    iVar3 = (**(code **)(*piVar2 + 8))();
  }
  if (iVar3 == 0xf) {
    iVar3 = *(int *)(*(int *)(in_ECX + 4) + 0x15c);
    if ((iVar3 == 0) || (*(int *)(*(int *)(in_ECX + 4) + 0x370) == 0)) {
      fVar6 = 0.0;
    }
    else {
      fVar6 = *(float *)(iVar3 + 0xb4);
    }
    if (((120.0 <= fVar6) && (fVar5 - fVar1 * param_1 * local_c < 120.0)) &&
       (iVar3 = FUN_0089289d(), 0.2 < (double)iVar3 / 32767.0)) {
      FUN_004c8d00(0x42200000);
      return;
    }
  }
  return;
}

