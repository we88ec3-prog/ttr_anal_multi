
void FUN_006bfca0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_006c07e0();
  FUN_00615fc0(200);
  FUN_0046b6f0(300);
  FUN_0046b6f0(500);
  FUN_0046b6f0(600);
  FUN_0046b6f0(900);
  FUN_0046b6f0(1000);
  FUN_0046b6f0(0x4b0);
  FUN_0046b6f0(0x578);
  FUN_0040e370(0x76c);
  FUN_0040e370(2000);
  FUN_0040e370(0x834);
  FUN_0040e370(0x898);
  FUN_0040e370(0x8fc);
  FUN_0040e370(0x960);
  FUN_0040e370(0xa28);
  FUN_0040e370(0xa8c);
  FUN_006c08d0();
  FUN_006c09c0(0x9ce);
  FUN_006c09c0(0x9d8);
  FUN_00615fc0(0x9e2);
  FUN_0046b6f0(0x9ec);
  iVar1 = *(int *)(in_ECX + 0xd4);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0xd4);
  if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
  }
  (**(code **)(**(int **)(in_ECX + 200) + 0xa0))(1);
  return;
}

