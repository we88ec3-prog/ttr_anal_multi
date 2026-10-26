
void FUN_004d1e10(short param_1,short param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  float fVar3;
  
  switch((int)param_1) {
  case 1:
    *(int *)(in_ECX + 0x3b0) = (int)param_2;
    iVar1 = FUN_007b4ed0(*(undefined4 *)(in_ECX + 0x368));
    *(float *)(iVar1 + 0xc) = (float)(int)param_2 * 0.0001;
    return;
  default:
    FUN_006edb60(&DAT_00c0c998,(int)param_1,(int)param_2);
    return;
  case 5:
    *(int *)(in_ECX + 0xd0) = (int)param_2;
    return;
  case 6:
    fVar3 = (float)(int)param_2;
    *(float *)(in_ECX + 0xcc) = fVar3;
    if (*(int *)(in_ECX + 0x420) == 0) {
      *(float *)(in_ECX + 0x394) = fVar3;
      *(undefined4 *)(in_ECX + 0x420) = 1;
    }
    break;
  case 0x17:
    *(int *)(in_ECX + 0x3d4) = (int)param_2;
    FUN_00425330();
    iVar1 = FUN_004f7a70();
    puVar2 = (undefined4 *)(iVar1 + 0x1c);
    if (7 < *(uint *)(iVar1 + 0x30)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    FUN_004d16e0(L"Lv.%d %s",*(undefined4 *)(in_ECX + 0x3d4),puVar2);
    return;
  case 0x1d:
    *(int *)(in_ECX + 0x90) = (int)param_2;
    return;
  }
  *(float *)(in_ECX + 0x398) = fVar3 / *(float *)(in_ECX + 0x394);
  return;
}

