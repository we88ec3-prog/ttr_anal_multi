
void FUN_00745380(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_0090f003;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FoxUI::FXUICmdTarget::vftable;
  local_8 = 3;
  puVar2 = (undefined4 *)in_ECX[0x14];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    if ((int *)puVar3[4] != (int *)0x0) {
      (**(code **)(*(int *)puVar3[4] + 0x1c))(1,uVar7);
      puVar3[4] = 0;
    }
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar6 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  FUN_00823850();
  piVar5 = (int *)in_ECX[0x19];
  piVar8 = (int *)*piVar5;
  *piVar5 = (int)piVar5;
  *(undefined4 *)(in_ECX[0x19] + 4) = in_ECX[0x19];
  in_ECX[0x1a] = 0;
  if (piVar8 != (int *)in_ECX[0x19]) {
    do {
      piVar5 = (int *)*piVar8;
      FUN_0089120c(piVar8);
      piVar8 = piVar5;
    } while (piVar5 != (int *)in_ECX[0x19]);
  }
  if ((int *)in_ECX[7] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[7] + 0x1c))(1);
    in_ECX[7] = 0;
  }
  if (((in_ECX[10] & 0x40000) == 0) && ((int *)in_ECX[0xf] != (int *)0x0)) {
    (**(code **)(*(int *)in_ECX[0xf] + 0x1c))(1);
    in_ECX[0xf] = 0;
  }
  piVar5 = (int *)in_ECX[0x1d];
  piVar8 = (int *)*piVar5;
  *piVar5 = (int)piVar5;
  *(undefined4 *)(in_ECX[0x1d] + 4) = in_ECX[0x1d];
  in_ECX[0x1e] = 0;
  if (piVar8 != (int *)in_ECX[0x1d]) {
    do {
      piVar5 = (int *)*piVar8;
      FUN_0089120c(piVar8);
      piVar8 = piVar5;
    } while (piVar5 != (int *)in_ECX[0x1d]);
  }
  FUN_0089120c(in_ECX[0x1d]);
  piVar5 = (int *)in_ECX[0x19];
  piVar8 = (int *)*piVar5;
  *piVar5 = (int)piVar5;
  *(undefined4 *)(in_ECX[0x19] + 4) = in_ECX[0x19];
  in_ECX[0x1a] = 0;
  if (piVar8 != (int *)in_ECX[0x19]) {
    do {
      piVar5 = (int *)*piVar8;
      FUN_0089120c(piVar8);
      piVar8 = piVar5;
    } while (piVar5 != (int *)in_ECX[0x19]);
  }
  FUN_0089120c(in_ECX[0x19]);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_005540c0(*(undefined4 *)in_ECX[0x14],(undefined4 *)in_ECX[0x14]);
  FUN_0089120c(in_ECX[0x14]);
  *in_ECX = FoxUI::FXUIArchive::vftable;
  ExceptionList = local_10;
  return;
}

