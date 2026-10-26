
void FUN_00577560(int param_1)

{
  float fVar1;
  int *piVar2;
  float *in_EAX;
  int *piVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  int iVar6;
  float fVar7;
  
  if (*(int *)(in_ECX + 0x108) != 0) {
    if ((*(int *)(in_ECX + 0x74) == 0) || (*(int *)(**(int **)(in_ECX + 0x104) + 8) != 8)) {
      fVar7 = 20.0;
    }
    else {
      fVar7 = 350.0;
    }
    if (*(int *)(in_ECX + 0x6c) != 0) {
      iVar6 = 0;
      do {
        FUN_00577320(iVar6);
        iVar6 = iVar6 + 1;
      } while (iVar6 < 3);
      piVar2 = *(int **)(in_ECX + 0x104);
      piVar3 = (int *)*piVar2;
      *piVar2 = (int)piVar2;
      *(int *)(*(int *)(in_ECX + 0x104) + 4) = *(int *)(in_ECX + 0x104);
      *(undefined4 *)(in_ECX + 0x108) = 0;
      if (piVar3 != *(int **)(in_ECX + 0x104)) {
        do {
          piVar2 = (int *)*piVar3;
          FUN_0089120c(piVar3);
          piVar3 = piVar2;
        } while (piVar2 != (int *)*(int *)(in_ECX + 0x104));
      }
      *(undefined4 *)(in_ECX + 0x6c) = 0;
      *(undefined4 *)(in_ECX + 200) = 8;
      return;
    }
    fVar1 = *(float *)(in_ECX + 0x1c + param_1 * 0x1c);
    iVar6 = in_ECX + param_1 * 0x1c;
    if (*(float *)(in_ECX + 0xe8) - fVar7 <= fVar1) {
      *(float *)(iVar6 + 0x1c) = fVar1 - *(float *)(in_ECX + 0xf0) * 150.0 * *in_EAX;
      return;
    }
    if (1.0 <= fVar1) {
      uVar5 = *(int *)(iVar6 + 0x24) - 0x31;
      *(float *)(iVar6 + 0x1c) = fVar1 - *in_EAX;
      iVar4 = (int)uVar5 >> 6;
      if (*(int *)(**(int **)(in_ECX + 0x104) + 8) == 8) {
        if (iVar4 == *(int *)(iVar6 + 0x14)) {
          if (*(int *)(in_ECX + 0x74) != 0) {
            uVar5 = uVar5 & 0x8000003f;
            if ((int)uVar5 < 0) {
              uVar5 = (uVar5 - 1 | 0xffffffc0) + 1;
            }
            if (0xb < (int)uVar5) {
              return;
            }
          }
          FUN_00577320(param_1);
          return;
        }
      }
      else if (iVar4 == *(int *)(iVar6 + 0x14)) {
        FUN_00577320(param_1);
        return;
      }
    }
  }
  return;
}

