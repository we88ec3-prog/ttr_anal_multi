
void FUN_006d57c0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  float local_10;
  float local_c;
  undefined1 local_8 [4];
  
  uVar2 = FUN_006dfbe0();
  *(undefined4 *)(in_ECX + 0x54) = uVar2;
  if (*(int *)(in_ECX + 4) != 0) {
    iVar3 = FUN_006dfca0();
    if (*(uint *)(iVar3 + 0xcc) < 0xffff0200) {
      *(undefined4 *)(in_ECX + 4) = 0;
      return;
    }
    puVar1 = (undefined4 *)(in_ECX + 0x34);
    iVar3 = D3DXCreateEffectFromFileA
                      (*(undefined4 *)(in_ECX + 0x54),"Material/Sepia.obj",0,0,1,0,puVar1,local_8);
    if (iVar3 == 0) {
      uVar2 = (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1,"Bloom");
      *(undefined4 *)(in_ECX + 0x38) = uVar2;
      uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"SceneMap");
      *(undefined4 *)(in_ECX + 0x3c) = uVar2;
      uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"DownsampleMap");
      *(undefined4 *)(in_ECX + 0x44) = uVar2;
      uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"HBlurMap");
      *(undefined4 *)(in_ECX + 0x48) = uVar2;
      uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"FinalBlurMap");
      *(undefined4 *)(in_ECX + 0x4c) = uVar2;
      uVar2 = (**(code **)(*(int *)*puVar1 + 0x24))((int *)*puVar1,0,"toneRatio");
      *(undefined4 *)(in_ECX + 0x50) = uVar2;
      iVar3 = FUN_00434740();
      local_10 = (float)*(int *)(*(int *)(iVar3 + 0x40) + 0xb4);
      local_c = (float)*(int *)(*(int *)(iVar3 + 0x40) + 0xb8);
      (**(code **)(*(int *)*puVar1 + 0x80))((int *)*puVar1,"WindowSize",&local_10,2);
    }
  }
  return;
}

