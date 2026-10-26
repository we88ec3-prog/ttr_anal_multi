
void FUN_007a7bf0(float param_1,float param_2,float param_3,undefined4 param_4)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  float local_14;
  float local_10;
  float local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(in_EAX + 0x1c);
  if (iVar1 != 0) {
    uVar2 = 0;
    *(float *)(in_EAX + 300) = param_1 * 0.78431374;
    *(float *)(in_EAX + 0x130) = param_2 * 0.78431374;
    *(float *)(in_EAX + 0x134) = param_3 * 0.78431374;
    local_10 = param_2;
    local_c = param_3;
    local_8 = param_4;
    *(undefined4 *)(in_EAX + 0x138) = param_4;
    local_14 = param_1;
    *(float *)(iVar1 + 0x50) = param_1;
    *(float *)(iVar1 + 0x54) = param_2;
    *(float *)(iVar1 + 0x58) = param_3;
    *(undefined4 *)(iVar1 + 0x5c) = param_4;
    uVar3 = *(int *)(iVar1 + 0xac) - *(int *)(iVar1 + 0xa8) >> 2;
    if (uVar3 != 0) {
      do {
        (**(code **)(**(int **)(*(int *)(iVar1 + 0xa8) + uVar2 * 4) + 4))(0,&local_14);
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar3);
    }
  }
  return;
}

