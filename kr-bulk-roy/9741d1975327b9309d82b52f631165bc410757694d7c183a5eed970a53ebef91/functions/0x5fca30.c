
void FUN_005fca30(int param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  int *piVar2;
  int iVar3;
  
  FUN_005f53c0(param_1);
  iVar3 = *(int *)(param_1 + 0x10);
  if (iVar3 == 0x578) {
    iVar3 = *(int *)(param_1 + 8);
    if (iVar3 == *(int *)(in_ECX[0x4b] + 0x20)) {
      iVar3 = *(int *)(*(int *)(*(int *)(in_ECX[0x41] + in_ECX[0x46] * 4) + 0xec) + 0xcc);
      if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 0xdc), iVar3 == 0)) {
        iVar3 = -1;
      }
      else {
        iVar3 = *(int *)(iVar3 + 0x20);
      }
      if (iVar3 + 1 != 0) {
        FUN_005fcc60(iVar3 + 1);
      }
    }
    else if (iVar3 == *(int *)(in_ECX[0x5b] + 0x20)) {
      FUN_005fd480(in_ECX);
    }
    else if (iVar3 == *(int *)(in_ECX[0x59] + 0x20)) {
      FUN_0040b5b0(0);
      puVar1 = (undefined4 *)FUN_00891268(0x18);
      if (puVar1 != (undefined4 *)0x0) {
        puVar1[1] = 0xffffffff;
        puVar1[2] = 0xffffffff;
        puVar1[3] = 0;
        puVar1[4] = 0x76c;
        *puVar1 = FoxUI::FXUIEventI1::vftable;
        puVar1[5] = 0;
      }
      FUN_00748900();
      (**(code **)(*(int *)in_ECX[0x5b] + 0x90))(1);
    }
    else if (iVar3 == *(int *)(in_ECX[0x5a] + 0x20)) {
      FUN_0040b5b0(1);
      puVar1 = (undefined4 *)FUN_00891268(0x18);
      if (puVar1 != (undefined4 *)0x0) {
        puVar1[1] = 0xffffffff;
        puVar1[2] = 0xffffffff;
        puVar1[3] = 0;
        puVar1[4] = 0x76c;
        *puVar1 = FoxUI::FXUIEventI1::vftable;
        puVar1[5] = 1;
      }
      FUN_00748900();
      (**(code **)(*(int *)in_ECX[0x5b] + 0x90))(0);
    }
    iVar3 = 0;
    piVar2 = in_ECX + 0x5c;
    do {
      if (*(int *)(param_1 + 8) == *(int *)(*piVar2 + 0x20)) {
        (**(code **)(*in_ECX + 0x1c0))(iVar3);
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < 5);
    return;
  }
  if (iVar3 != 0xf4397) {
    if (iVar3 == 0xf4398) {
      FUN_005fb8c0(in_ECX);
      return;
    }
    if (iVar3 == 0xf4425) {
      iVar3 = FUN_004068c0();
      if (*(int *)(iVar3 + 0x14) == 0x6a7) {
        iVar3 = FUN_00412b10();
        FUN_005fd080(*(undefined4 *)(iVar3 + 0x14),*(undefined4 *)(iVar3 + 0x18));
        return;
      }
    }
    else if (iVar3 == 0xf4399) {
      if (*(int *)(param_1 + 0x14) == 0x6a7) {
        FUN_005fc820();
        return;
      }
    }
    else if ((iVar3 == 0xf4386) && (iVar3 = FUN_004068c0(), *(int *)(iVar3 + 0x14) == 0x6a7)) {
      FUN_005fdce0();
    }
    return;
  }
  FUN_005fb860(in_ECX);
  return;
}

