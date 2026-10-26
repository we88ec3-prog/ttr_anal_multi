
void FUN_0075e8a0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  FUN_0082ef00(&local_8);
  iVar1 = *(int *)(in_ECX + 0x50);
  if (local_c == iVar1) {
    local_8 = 0;
  }
  else {
    local_8 = *(int *)(local_c + 0x10);
  }
  *(int *)(in_ECX + 0xa4) = local_8;
  local_c = 1;
  FUN_0082ef00(&local_c);
  if (local_10 == iVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(local_10 + 0x10);
  }
  *(undefined4 *)(in_ECX + 0xa8) = uVar2;
  local_10 = 2;
  FUN_0082ef00(&local_10);
  if (local_c == iVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(local_c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0xac) = uVar2;
  local_10 = 3;
  FUN_0082ef00(&local_10);
  if (local_c == iVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(local_c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0xb0) = uVar2;
  local_10 = 4;
  FUN_0082ef00(&local_10);
  if (local_c == iVar1) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(local_c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0xb4) = uVar2;
  *(undefined1 *)(local_8 + 0xa4) = 0;
  *(undefined1 *)(*(int *)(in_ECX + 0xa8) + 0xa4) = 0;
  *(undefined1 *)(*(int *)(in_ECX + 0xac) + 0xa4) = 0;
  *(undefined1 *)(*(int *)(in_ECX + 0xb0) + 0xa4) = 0;
  *(undefined1 *)(*(int *)(in_ECX + 0xb4) + 0xa4) = 0;
  return;
}

