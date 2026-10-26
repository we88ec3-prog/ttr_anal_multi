
void FUN_0050c0a0(int param_1,uint param_2,int param_3,uint param_4,int param_5,uint param_6)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  code *unaff_EDI;
  
  uVar2 = param_2;
  if (*(uint *)(param_1 + 8) <= param_2) {
    uVar2 = param_2 - *(uint *)(param_1 + 8);
  }
  uVar3 = param_4;
  if (*(uint *)(param_3 + 8) <= param_4) {
    uVar3 = param_4 - *(uint *)(param_3 + 8);
  }
  cVar1 = (*unaff_EDI)(*(undefined4 *)(*(int *)(param_3 + 4) + uVar3 * 4),
                       *(undefined4 *)(*(int *)(param_1 + 4) + uVar2 * 4));
  if (cVar1 != '\0') {
    FUN_0050bcc0(param_3,param_4,param_1,param_2);
  }
  uVar2 = param_4;
  if (*(uint *)(param_3 + 8) <= param_4) {
    uVar2 = param_4 - *(uint *)(param_3 + 8);
  }
  uVar3 = param_6;
  if (*(uint *)(param_5 + 8) <= param_6) {
    uVar3 = param_6 - *(uint *)(param_5 + 8);
  }
  cVar1 = (*unaff_EDI)(*(undefined4 *)(*(int *)(param_5 + 4) + uVar3 * 4),
                       *(undefined4 *)(*(int *)(param_3 + 4) + uVar2 * 4));
  if (cVar1 != '\0') {
    FUN_0050bcc0(param_5,param_6,param_3,param_4);
  }
  uVar2 = param_2;
  if (*(uint *)(param_1 + 8) <= param_2) {
    uVar2 = param_2 - *(uint *)(param_1 + 8);
  }
  uVar3 = param_4;
  if (*(uint *)(param_3 + 8) <= param_4) {
    uVar3 = param_4 - *(uint *)(param_3 + 8);
  }
  cVar1 = (*unaff_EDI)(*(undefined4 *)(*(int *)(param_3 + 4) + uVar3 * 4),
                       *(undefined4 *)(*(int *)(param_1 + 4) + uVar2 * 4));
  if (cVar1 != '\0') {
    FUN_0050bcc0(param_3,param_4,param_1,param_2);
  }
  return;
}

