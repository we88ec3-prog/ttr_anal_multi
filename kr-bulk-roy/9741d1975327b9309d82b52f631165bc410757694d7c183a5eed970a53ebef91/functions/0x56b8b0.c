
void FUN_0056b8b0(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  float fVar4;
  undefined4 local_14;
  undefined4 local_c;
  
  iVar1 = 6 - *(int *)(in_ECX + 0x14);
  if (iVar1 < 1) {
    *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(in_ECX + 0x1c);
  }
  else {
    *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x1c) + iVar1 * -0x14;
  }
  FUN_00542210();
  iVar1 = FUN_004d8460();
  if (local_c != *(uint *)(iVar1 + 8)) {
    iVar1 = 0xb7;
    do {
      if (local_14 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *local_14;
      }
      uVar2 = local_c;
      if (*(uint *)(iVar3 + 8) <= local_c) {
        uVar2 = local_c - *(uint *)(iVar3 + 8);
      }
      iVar3 = *(int *)(*(int *)(iVar3 + 4) + uVar2 * 4);
      if (0x77 < *(int *)(iVar3 + 0x20c)) {
        *(undefined4 *)(iVar3 + 0x204) = 1;
      }
      if (*(int *)(iVar3 + 0x204) == 0) {
        fVar4 = (float)iVar1;
LAB_0056b96a:
        *(float *)(iVar3 + 0x208) = fVar4;
      }
      else {
        fVar4 = *(float *)(iVar3 + 0x208) - 2.0;
        *(float *)(iVar3 + 0x208) = fVar4;
        if (fVar4 <= 0.0) {
          fVar4 = 0.0;
          goto LAB_0056b96a;
        }
      }
      local_c = local_c + 1;
      iVar1 = iVar1 + 0xc;
      iVar3 = FUN_004d8460();
    } while (local_c != *(uint *)(iVar3 + 8));
  }
  return;
}

