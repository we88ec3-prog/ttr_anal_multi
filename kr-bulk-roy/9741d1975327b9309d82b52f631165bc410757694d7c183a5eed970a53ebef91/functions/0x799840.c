
void FUN_00799840(void)

{
  int *piVar1;
  int in_EAX;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(int *)(in_EAX + 0xa0) == 0) {
    puVar2 = (undefined4 *)FUN_00891268(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = IS3D::CFixedRenderPipeline::vftable;
    }
    *(undefined4 **)(in_EAX + 0xa0) = puVar2;
  }
  piVar1 = *(int **)(in_EAX + 0x9c);
  uVar4 = 0;
  uVar3 = piVar1[1] - *piVar1 >> 2;
  if (uVar3 != 0) {
    do {
      (**(code **)(**(int **)(*piVar1 + uVar4 * 4) + 0x10))();
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  return;
}

