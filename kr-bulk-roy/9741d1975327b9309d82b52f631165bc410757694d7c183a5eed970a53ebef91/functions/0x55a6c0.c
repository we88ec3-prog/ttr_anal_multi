
void FUN_0055a6c0(int param_1)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  float *pfVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    fVar1 = *(float *)(param_1 + 0x48);
    fVar2 = *(float *)(param_1 + 0x4c);
    uVar3 = *(undefined4 *)(param_1 + 0x50);
    iVar5 = 0;
    pfVar4 = (float *)(param_1 + 0x5c);
    do {
      (**(code **)(**(int **)(param_1 + 0x54) + 0xc))
                (pfVar4[-1] + fVar1,*pfVar4 + fVar2,uVar3,pfVar4[0x11],pfVar4[0x12],0,DAT_00f7f970,
                 DAT_00f7f974,DAT_00f7f978,DAT_00f7f97c,iVar5,0,0x3f800000,0x3f800000,0x3f800000,
                 0x3f800000);
      iVar5 = iVar5 + 1;
      pfVar4 = pfVar4 + 2;
    } while (iVar5 < 9);
    FUN_00739180(*(float *)(param_1 + 0xf0) * 0.5 + fVar1,(*(float *)(param_1 + 0xf4) - 1.0) + fVar2
                 ,uVar3,9,0,0x3f800000,0x3f800000,0x3f800000,0x3f800000);
  }
  return;
}

