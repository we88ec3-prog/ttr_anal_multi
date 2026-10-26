
void FUN_0074e0b0(void)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090eebc;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUI::vftable;
  local_8 = 0xd;
  in_ECX[0x4f1] = 0;
  FUN_00753830(uVar1);
  FUN_00753830();
  FUN_00753890();
  iVar3 = in_ECX[0x515];
  while (iVar3 != 0) {
    iVar3 = 0;
    piVar2 = (int *)FUN_00542210();
    if ((int *)*piVar2 != (int *)0x0) {
      iVar3 = *(int *)*piVar2;
    }
    uVar1 = (uint)piVar2[2] >> 1;
    if (*(uint *)(iVar3 + 8) <= uVar1) {
      uVar1 = uVar1 - *(uint *)(iVar3 + 8);
    }
    piVar2 = *(int **)(*(int *)(*(int *)(iVar3 + 4) + uVar1 * 4) + (piVar2[2] & 1U) * 8 + 4);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x10))(1);
    }
    if (in_ECX[0x515] != 0) {
      in_ECX[0x514] = in_ECX[0x514] + 1;
      if ((uint)(in_ECX[0x513] * 2) <= (uint)in_ECX[0x514]) {
        in_ECX[0x514] = 0;
      }
      iVar3 = in_ECX[0x515] + -1;
      in_ECX[0x515] = iVar3;
      if (iVar3 == 0) {
        in_ECX[0x514] = 0;
      }
    }
    iVar3 = in_ECX[0x515];
  }
  FUN_00753520();
  local_8._0_1_ = 0xc;
  _eh_vector_destructor_iterator_(in_ECX + 0x567,0x1c,0xc00,FUN_005f5d10);
  local_8._0_1_ = 0xb;
  _eh_vector_destructor_iterator_(in_ECX + 0x549,0x1c,4,FUN_005f5d10);
  local_8 = CONCAT31(local_8._1_3_,10);
  _eh_vector_destructor_iterator_(in_ECX + 0x535,0x14,4,FUN_005f5d10);
  piVar2 = (int *)in_ECX[0x532];
  piVar4 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(undefined4 *)(in_ECX[0x532] + 4) = in_ECX[0x532];
  in_ECX[0x533] = 0;
  if (piVar4 != (int *)in_ECX[0x532]) {
    do {
      piVar2 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar2;
    } while (piVar2 != (int *)in_ECX[0x532]);
  }
  FUN_0089120c(in_ECX[0x532]);
  if (in_ECX[0x527] != 0) {
    FUN_0089120c(in_ECX[0x527]);
  }
  in_ECX[0x527] = 0;
  in_ECX[0x528] = 0;
  in_ECX[0x529] = 0;
  if (in_ECX[0x523] != 0) {
    FUN_0089120c(in_ECX[0x523]);
  }
  in_ECX[0x523] = 0;
  in_ECX[0x524] = 0;
  in_ECX[0x525] = 0;
  piVar2 = (int *)in_ECX[0x520];
  piVar4 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(undefined4 *)(in_ECX[0x520] + 4) = in_ECX[0x520];
  in_ECX[0x521] = 0;
  if (piVar4 != (int *)in_ECX[0x520]) {
    do {
      piVar2 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar2;
    } while (piVar2 != (int *)in_ECX[0x520]);
  }
  FUN_0089120c(in_ECX[0x520]);
  piVar2 = (int *)in_ECX[0x51d];
  piVar4 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(undefined4 *)(in_ECX[0x51d] + 4) = in_ECX[0x51d];
  in_ECX[0x51e] = 0;
  if (piVar4 != (int *)in_ECX[0x51d]) {
    do {
      piVar2 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar2;
    } while (piVar2 != (int *)in_ECX[0x51d]);
  }
  FUN_0089120c(in_ECX[0x51d]);
  FUN_007b6d70();
  FUN_0089120c(in_ECX[0x517]);
  in_ECX[0x517] = 0;
  FUN_007b6d70();
  FUN_0089120c(in_ECX[0x511]);
  in_ECX[0x511] = 0;
  piVar2 = (int *)in_ECX[0x50e];
  piVar4 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(undefined4 *)(in_ECX[0x50e] + 4) = in_ECX[0x50e];
  in_ECX[0x50f] = 0;
  if (piVar4 != (int *)in_ECX[0x50e]) {
    do {
      piVar2 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar2;
    } while (piVar2 != (int *)in_ECX[0x50e]);
  }
  FUN_0089120c(in_ECX[0x50e]);
  piVar2 = (int *)in_ECX[0x50b];
  piVar4 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(undefined4 *)(in_ECX[0x50b] + 4) = in_ECX[0x50b];
  in_ECX[0x50c] = 0;
  if (piVar4 != (int *)in_ECX[0x50b]) {
    do {
      piVar2 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar2;
    } while (piVar2 != (int *)in_ECX[0x50b]);
  }
  FUN_0089120c(in_ECX[0x50b]);
  piVar2 = (int *)in_ECX[0x508];
  piVar4 = (int *)*piVar2;
  *piVar2 = (int)piVar2;
  *(undefined4 *)(in_ECX[0x508] + 4) = in_ECX[0x508];
  in_ECX[0x509] = 0;
  if (piVar4 != (int *)in_ECX[0x508]) {
    do {
      piVar2 = (int *)*piVar4;
      FUN_0089120c(piVar4);
      piVar4 = piVar2;
    } while (piVar2 != (int *)in_ECX[0x508]);
  }
  FUN_0089120c(in_ECX[0x508]);
  local_8 = 0xe;
  FUN_005540c0(*(undefined4 *)in_ECX[0x505],(undefined4 *)in_ECX[0x505]);
  FUN_0089120c(in_ECX[0x505]);
  ExceptionList = local_10;
  return;
}

