
void FUN_00645170(uint param_1)

{
  int in_EAX;
  int unaff_EDI;
  
  (**(code **)(**(int **)(*(int *)(unaff_EDI + 0x13c + in_EAX * 4) + 0xa8) + 0xa0))
            ((byte)param_1 & 1);
  (**(code **)(**(int **)(*(int *)(unaff_EDI + 0x13c + in_EAX * 4) + 0xac) + 0xa0))
            ((byte)(param_1 >> 2) & 1);
  (**(code **)(**(int **)(*(int *)(unaff_EDI + 0x13c + in_EAX * 4) + 0xb0) + 0xa0))
            ((byte)(param_1 >> 3) & 1);
  (**(code **)(**(int **)(*(int *)(unaff_EDI + 0x13c + in_EAX * 4) + 0xb4) + 0xa0))
            ((byte)(param_1 >> 1) & 1);
  (**(code **)(**(int **)(*(int *)(unaff_EDI + 0x13c + in_EAX * 4) + 0xb8) + 0xa0))
            ((byte)(param_1 >> 4) & 1);
  (**(code **)(**(int **)(*(int *)(unaff_EDI + 0x13c + in_EAX * 4) + 0xbc) + 0xa0))
            ((byte)(param_1 >> 5) & 1);
  return;
}

