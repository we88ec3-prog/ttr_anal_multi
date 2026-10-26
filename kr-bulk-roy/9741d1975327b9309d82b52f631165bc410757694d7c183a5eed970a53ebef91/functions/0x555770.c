
undefined4 FUN_00555770(void)

{
  undefined4 in_EAX;
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int *piVar3;
  
  *(undefined4 *)(in_ECX + 0x84) = in_EAX;
  if (*(int *)(in_ECX + 0x30) != 0) {
    piVar3 = (int *)(in_ECX + 0x20);
    if (0xf < *(uint *)(in_ECX + 0x34)) {
      piVar3 = (int *)*piVar3;
    }
    FUN_006dfbe0();
    iVar1 = FUN_00737f40(piVar3,0xffffffff,0,(undefined4 *)(in_ECX + 0x74));
    if (iVar1 < 0) {
      FUN_006edb60("Failed to load background texture");
    }
    else {
      piVar3 = *(int **)(in_ECX + 0x74);
      (**(code **)(*piVar3 + 0x44))(piVar3,0,in_ECX + 0x88);
    }
    if (*(uint *)(in_ECX + 0x50) < 0x10) {
      iVar1 = in_ECX + 0x3c;
    }
    else {
      iVar1 = *(int *)(in_ECX + 0x3c);
    }
    FUN_006dfbe0();
    iVar1 = FUN_00737f40(iVar1,0xffffffff,0,(undefined4 *)(in_ECX + 0x78));
    if (iVar1 < 0) {
      FUN_006edb60("Failed to load tooltip texture");
    }
    else {
      piVar3 = *(int **)(in_ECX + 0x78);
      (**(code **)(*piVar3 + 0x44))(piVar3,0,in_ECX + 0xa8);
    }
    if (*(uint *)(in_ECX + 0x6c) < 0x10) {
      iVar1 = in_ECX + 0x58;
    }
    else {
      iVar1 = *(int *)(in_ECX + 0x58);
    }
    FUN_006dfbe0();
    iVar1 = FUN_00737f40(iVar1,0x20,0,(undefined4 *)(in_ECX + 0x7c));
    if (iVar1 < 0) {
      FUN_006edb60("Failed to load tooltip texture");
    }
    else {
      piVar3 = *(int **)(in_ECX + 0x7c);
      (**(code **)(*piVar3 + 0x44))(piVar3,0,in_ECX + 200);
    }
    uVar2 = FUN_006dfbe0();
    iVar1 = D3DXCreateFontW(uVar2,0x14,0,700,1,0,1,0,0,0,PTR_DAT_00d6a234,in_ECX + 0x80);
    if (iVar1 < 0) {
      FUN_006edb60("Failed to load Font");
    }
  }
  return 0;
}

