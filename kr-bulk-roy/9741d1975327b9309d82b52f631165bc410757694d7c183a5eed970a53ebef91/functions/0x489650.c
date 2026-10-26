
void FUN_00489650(void)

{
  undefined4 *puVar1;
  float fVar2;
  int *piVar3;
  int in_EAX;
  int iVar4;
  int in_ECX;
  float10 fVar5;
  double local_18;
  double local_10;
  
  fVar2 = *(float *)(in_ECX + 4 + in_EAX * 0x14);
  puVar1 = (undefined4 *)(in_ECX + in_EAX * 0x14);
  switch(*puVar1) {
  case 1:
    iVar4 = FUN_00434740();
    fVar5 = (float10)FUN_008ff0a0();
    *(float *)(*(int *)(iVar4 + 0x40) + 0x28) = ((-fVar2 + 36.0) * (float)fVar5) / 40.0;
    return;
  case 2:
    iVar4 = FUN_00434740();
    local_18 = 2700.0;
    local_10 = (double)*(float *)(*(int *)(iVar4 + 0x40) + 0x18);
    fVar5 = (float10)FUN_00489620(&local_18);
    local_18 = (double)CONCAT44(local_18._4_4_,(float)local_10 - (float)(fVar5 / (float10)90.0));
    iVar4 = FUN_00434740();
    iVar4 = *(int *)(iVar4 + 0x40);
    *(float *)(iVar4 + 0x18) = local_18._0_4_;
    *(undefined4 *)(iVar4 + 0xcc) = 0;
    return;
  case 3:
    iVar4 = FUN_00434740();
    local_10 = 3.0;
    local_18 = (double)fVar2;
    fVar5 = (float10)FUN_00489620(&local_10);
    local_18 = (double)CONCAT44(local_18._4_4_,
                                (float)(fVar5 / (float10)400.0) +
                                *(float *)(*(int *)(iVar4 + 0x40) + 0x34));
    iVar4 = FUN_00434740();
    piVar3 = *(int **)(iVar4 + 0x40);
    piVar3[0x33] = 0;
    if (*piVar3 != 0) {
      *(float *)(*piVar3 + 0x74) = (local_18._0_4_ / 1.3333334) * (float)piVar3[0x2f];
      return;
    }
    break;
  case 4:
    iVar4 = FUN_00434740();
    local_10 = 3.0;
    local_18 = (double)fVar2;
    fVar2 = *(float *)(*(int *)(iVar4 + 0x40) + 0x34);
    fVar5 = (float10)FUN_00489620(&local_10);
    local_18 = (double)CONCAT44(local_18._4_4_,fVar2 - (float)(fVar5 / (float10)80.0));
    iVar4 = FUN_00434740();
    piVar3 = *(int **)(iVar4 + 0x40);
    piVar3[0x33] = 0;
    if (*piVar3 != 0) {
      *(float *)(*piVar3 + 0x74) = (local_18._0_4_ / 1.3333334) * (float)piVar3[0x2f];
      return;
    }
    break;
  case 5:
    iVar4 = FUN_00434740();
    local_10 = 3.0;
    local_18 = (double)fVar2;
    fVar5 = (float10)FUN_00489620(&local_10);
    local_18 = (double)CONCAT44(local_18._4_4_,
                                (float)(fVar5 / (float10)40.0) +
                                *(float *)(*(int *)(iVar4 + 0x40) + 0x34));
    iVar4 = FUN_00434740();
    piVar3 = *(int **)(iVar4 + 0x40);
    piVar3[0x33] = 0;
    if (*piVar3 != 0) {
      *(float *)(*piVar3 + 0x74) = (local_18._0_4_ / 1.3333334) * (float)piVar3[0x2f];
      return;
    }
    break;
  case 10:
    iVar4 = FUN_00434740();
    fVar5 = (float10)FUN_008ff0a0();
    *(float *)(*(int *)(iVar4 + 0x40) + 0x28) =
         ((-fVar2 + (float)(int)puVar1[3]) * (float)fVar5) / (float)(int)puVar1[4];
  }
  return;
}

