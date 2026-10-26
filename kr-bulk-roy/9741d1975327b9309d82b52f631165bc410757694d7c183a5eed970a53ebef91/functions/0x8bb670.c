
void FUN_008bb670(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar1 = *(int *)(param_3 + 0xc);
  if (*(code **)(param_2 + 0x78) != (code *)0x0) {
    (**(code **)(param_2 + 0x78))(*(undefined4 *)(param_2 + 0x74));
  }
  iVar2 = *(int *)(param_2 + 0x54);
  while (iVar2 != 0) {
    FUN_008ba460(*(undefined4 *)(param_2 + 0x54));
    iVar2 = *(int *)(param_2 + 0x54);
  }
  FUN_008ba140(param_2 + 0x6c,FUN_008ba4d0,param_1,param_3);
  *(undefined4 *)(param_2 + 0x58) = 0;
  if (*(code **)(param_2 + 0x30) != (code *)0x0) {
    (**(code **)(param_2 + 0x30))(param_2);
  }
  FUN_008bb620(param_1);
  pcVar3 = *(code **)(iVar1 + 0x34);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(param_2);
  }
  FUN_008ba2d0(*(undefined4 *)(param_2 + 0x68),*(uint *)(param_2 + 8) >> 10 & 1);
  *(undefined4 *)(param_2 + 0x68) = 0;
  if (*(int *)(param_2 + 0x80) != 0) {
    FUN_008b9f80(param_1,*(int *)(param_2 + 0x80));
    *(undefined4 *)(param_2 + 0x80) = 0;
  }
  FUN_008b9f80(param_1,param_2);
  return;
}

