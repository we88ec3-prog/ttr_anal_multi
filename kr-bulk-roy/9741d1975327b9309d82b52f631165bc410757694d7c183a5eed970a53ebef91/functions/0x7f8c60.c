
void FUN_007f8c60(int param_1)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int in_ECX;
  
  *(undefined1 *)(param_1 + 0x58) = 1;
  FUN_007f88a0(param_1);
  if (*(int *)(in_ECX + 0xfc) == 0) {
    uVar1 = *(undefined4 *)(in_ECX + 0xf8);
  }
  else {
    uVar1 = *(undefined4 *)(in_ECX + 0xec);
  }
  *(undefined4 *)(param_1 + 8) = uVar1;
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(in_ECX + 0x100);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(in_ECX + 0x104);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(in_ECX + 0x108);
  iVar5 = FUN_0089289d();
  fVar4 = (float)(iVar5 % 10000) * 0.0001 * 1.0 + 0.0;
  fVar2 = *(float *)(in_ECX + 0x11c);
  fVar3 = *(float *)(in_ECX + 0x120);
  *(float *)(param_1 + 0x18) = fVar4 * *(float *)(in_ECX + 0x118);
  *(float *)(param_1 + 0x1c) = fVar2 * fVar4;
  *(float *)(param_1 + 0x20) = fVar4 * fVar3;
  iVar5 = FUN_0089289d();
  *(float *)(param_1 + 0xc) =
       *(float *)(in_ECX + 0x10c) * ((float)(iVar5 % 10000) * 0.0001 - 0.5) +
       *(float *)(param_1 + 0xc);
  iVar5 = FUN_0089289d();
  *(float *)(param_1 + 0x10) =
       *(float *)(in_ECX + 0x110) * ((float)(iVar5 % 10000) * 0.0001 - 0.5) +
       *(float *)(param_1 + 0x10);
  iVar5 = FUN_0089289d();
  *(float *)(param_1 + 0x14) =
       *(float *)(in_ECX + 0x114) * ((float)(iVar5 % 10000) * 0.0001 - 0.5) +
       *(float *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x38) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x40) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x44) = 0x3f800000;
  return;
}

