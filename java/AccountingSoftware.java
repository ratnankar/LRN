import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.text.SimpleDateFormat;

public class AccountingSoftware extends JFrame {

    private ArrayList<JournalEntry> journalEntries = new ArrayList<>();
    private HashMap<String, LedgerAccount> ledgerAccounts = new HashMap<>();
    private ArrayList<TrialBalanceEntry> trialBalance = new ArrayList<>();
    private double closingStock = 0;

    private final Color PRIMARY_COLOR = new Color(0, 102, 153);
    private final Color BACKGROUND_COLOR = new Color(250, 250, 252);
    private final Color PANEL_COLOR = Color.WHITE;
    private final Color BORDER_COLOR = new Color(220, 220, 220);
    private final Color BUTTON_COLOR = new Color(0, 70, 120);
    private final Color BUTTON_HOVER_COLOR = new Color(0, 50, 90);
    private final Color FINANCIAL_STATEMENTS_COLOR = new Color(0, 80, 120);

    private final Font HEADER_FONT = new Font("Segoe UI", Font.BOLD, 14);
    private final Font LABEL_FONT = new Font("Segoe UI", Font.PLAIN, 12);
    private final Font MONOSPACE_FONT = new Font("Consolas", Font.PLAIN, 12);

    private JTabbedPane tabbedPane;
    private JPanel journalPanel, ledgerPanel, trialBalancePanel, financialStatementsPanel;

    private JTextField dateField, debitAccountField, creditAccountField, amountField;
    private JButton addJournalEntryButton;
    private JTextArea journalEntriesArea;

    private JComboBox<String> ledgerAccountComboBox;
    private JTextArea ledgerDetailsArea;

    private JTextArea trialBalanceArea;
    private JTextField closingStockField;
    private JButton generateTrialBalanceButton;

    private JTextArea tradingAccountArea, plAccountArea, balanceSheetArea;
    private JButton generateFinancialStatementsButton;

    public AccountingSoftware() {
        setTitle("Accountech : Sole Proprietorship Accounting Software");
        setSize(1100, 750);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        getContentPane().setBackground(BACKGROUND_COLOR);

        tabbedPane = new JTabbedPane(JTabbedPane.TOP, JTabbedPane.SCROLL_TAB_LAYOUT);

        createJournalPanel();
        createLedgerPanel();
        createTrialBalancePanel();
        createFinancialStatementsPanel();

        tabbedPane.addTab("Journal Entries", journalPanel);
        tabbedPane.addTab("Ledger Accounts", ledgerPanel);
        tabbedPane.addTab("Trial Balance", trialBalancePanel);
        tabbedPane.addTab("Financial Statements", financialStatementsPanel);

        add(tabbedPane, BorderLayout.CENTER);
    }

    private JPanel createStyledPanel(String title) {
        JPanel panel = new JPanel();
        panel.setBackground(PANEL_COLOR);
        panel.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createTitledBorder(
                BorderFactory.createLineBorder(BORDER_COLOR, 1),
                title,
                TitledBorder.LEFT,
                TitledBorder.TOP,
                new Font("Segoe UI", Font.BOLD, 12),
                new Color(0, 0, 139)
            ),
            BorderFactory.createEmptyBorder(10, 10, 10, 10)
        ));
        return panel;
    }

    private void styleButtonDark(JButton button) {
        button.setBackground(BUTTON_COLOR);
        button.setForeground(Color.BLACK); // Changed to black text
        button.setFont(new Font("Segoe UI", Font.BOLD, 12));
        button.setFocusPainted(false);
        button.setBorder(BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(new Color(0, 30, 60)),
            BorderFactory.createEmptyBorder(8, 20, 8, 20)
        ));

        button.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseEntered(MouseEvent e) {
                button.setBackground(BUTTON_HOVER_COLOR);
            }

            @Override
            public void mouseExited(MouseEvent e) {
                button.setBackground(BUTTON_COLOR);
            }
        });
    }

    private JButton createStyledButton(String text) {
        JButton button = new JButton(text);
        styleButtonDark(button);
        return button;
    }

    private void createJournalPanel() {
        journalPanel = new JPanel(new BorderLayout(10, 10));
        journalPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
        journalPanel.setBackground(PANEL_COLOR);

        JPanel inputPanel = createStyledPanel("Add New Journal Entry");
        inputPanel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);
        gbc.anchor = GridBagConstraints.WEST;
        gbc.fill = GridBagConstraints.HORIZONTAL;

        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");
        dateField = new JTextField(dateFormat.format(new Date()));
        dateField.setBorder(BorderFactory.createLineBorder(BORDER_COLOR));

        gbc.gridx = 0;
        gbc.gridy = 0;
        inputPanel.add(new JLabel("Date (YYYY-MM-DD):"), gbc);
        gbc.gridx = 1;
        gbc.gridwidth = 3;
        inputPanel.add(dateField, gbc);

        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.gridwidth = 1;
        inputPanel.add(new JLabel("Debit Account:"), gbc);

        debitAccountField = new JTextField();
        debitAccountField.setBorder(BorderFactory.createLineBorder(BORDER_COLOR));
        gbc.gridx = 1;
        inputPanel.add(debitAccountField, gbc);

        String[] accountTypes = {"Asset", "Liability", "Equity", "Revenue", "Expense"};
        JComboBox<String> debitAccountTypeCombo = new JComboBox<>(accountTypes);
        gbc.gridx = 2;
        inputPanel.add(debitAccountTypeCombo, gbc);

        gbc.gridx = 0;
        gbc.gridy = 2;
        inputPanel.add(new JLabel("Credit Account:"), gbc);

        creditAccountField = new JTextField();
        creditAccountField.setBorder(BorderFactory.createLineBorder(BORDER_COLOR));
        gbc.gridx = 1;
        inputPanel.add(creditAccountField, gbc);

        JComboBox<String> creditAccountTypeCombo = new JComboBox<>(accountTypes);
        gbc.gridx = 2;
        inputPanel.add(creditAccountTypeCombo, gbc);

        gbc.gridx = 0;
        gbc.gridy = 3;
        inputPanel.add(new JLabel("Amount:"), gbc);

        amountField = new JTextField();
        amountField.setBorder(BorderFactory.createLineBorder(BORDER_COLOR));
        gbc.gridx = 1;
        gbc.gridwidth = 2;
        inputPanel.add(amountField, gbc);

        addJournalEntryButton = createStyledButton("Add Journal Entry");
        gbc.gridx = 1;
        gbc.gridy = 4;
        gbc.gridwidth = 1;
        gbc.anchor = GridBagConstraints.CENTER;
        inputPanel.add(addJournalEntryButton, gbc);

        KeyAdapter enterKeyAdapter = new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    addJournalEntry(debitAccountTypeCombo, creditAccountTypeCombo);
                }
            }
        };

        dateField.addKeyListener(enterKeyAdapter);
        debitAccountField.addKeyListener(enterKeyAdapter);
        creditAccountField.addKeyListener(enterKeyAdapter);
        amountField.addKeyListener(enterKeyAdapter);
        addJournalEntryButton.addActionListener(e -> addJournalEntry(debitAccountTypeCombo, creditAccountTypeCombo));

        journalEntriesArea = new JTextArea();
        journalEntriesArea.setEditable(false);
        journalEntriesArea.setFont(MONOSPACE_FONT);
        JScrollPane scrollPane = new JScrollPane(journalEntriesArea);
        scrollPane.setBorder(BorderFactory.createTitledBorder(
            BorderFactory.createLineBorder(BORDER_COLOR),
            "Journal Entries",
            TitledBorder.LEFT,
            TitledBorder.TOP,
            HEADER_FONT,
            new Color(0, 0, 139)
        ));

        journalPanel.add(inputPanel, BorderLayout.NORTH);
        journalPanel.add(scrollPane, BorderLayout.CENTER);
    }

    private void createLedgerPanel() {
        ledgerPanel = new JPanel(new BorderLayout(10, 10));
        ledgerPanel.setBorder(new EmptyBorder(10, 10, 10, 10));
        ledgerPanel.setBackground(PANEL_COLOR);

        JPanel topPanel = createStyledPanel("View Ledger Account");
        topPanel.setLayout(new FlowLayout(FlowLayout.LEFT, 10, 10));

        ledgerAccountComboBox = new JComboBox<>();
        ledgerAccountComboBox.setPreferredSize(new Dimension(200, 25));
        updateLedgerComboBox();

        JButton viewLedgerButton = createStyledButton("Show Ledger");
        viewLedgerButton.addActionListener(e -> viewLedger());

        topPanel.add(new JLabel("Select Account:"));
        topPanel.add(ledgerAccountComboBox);
        topPanel.add(viewLedgerButton);

        ledgerDetailsArea = new JTextArea();
        ledgerDetailsArea.setEditable(false);
        ledgerDetailsArea.setFont(MONOSPACE_FONT);
        JScrollPane scrollPane = new JScrollPane(ledgerDetailsArea);
        scrollPane.setBorder(BorderFactory.createTitledBorder(
            BorderFactory.createLineBorder(BORDER_COLOR),
            "Ledger Details",
            TitledBorder.LEFT,
            TitledBorder.TOP,
            HEADER_FONT,
            new Color(0, 0, 139)
        ));

        ledgerPanel.add(topPanel, BorderLayout.NORTH);
        ledgerPanel.add(scrollPane, BorderLayout.CENTER);
    }

    private void createTrialBalancePanel() {
        trialBalancePanel = new JPanel(new BorderLayout(10, 10));
        trialBalancePanel.setBorder(new EmptyBorder(10, 10, 10, 10));
        trialBalancePanel.setBackground(PANEL_COLOR);

        JPanel inputPanel = createStyledPanel("Generate Trial Balance");
        inputPanel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);
        gbc.anchor = GridBagConstraints.WEST;

        gbc.gridx = 0;
        gbc.gridy = 0;
        inputPanel.add(new JLabel("Closing Stock Value:"), gbc);

        closingStockField = new JTextField("0");
        closingStockField.setBorder(BorderFactory.createLineBorder(BORDER_COLOR));
        gbc.gridx = 1;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        inputPanel.add(closingStockField, gbc);

        generateTrialBalanceButton = createStyledButton("Generate Trial Balance");
        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.gridwidth = 2;
        gbc.anchor = GridBagConstraints.CENTER;
        inputPanel.add(generateTrialBalanceButton, gbc);

        generateTrialBalanceButton.addActionListener(e -> {
            try {
                closingStock = Double.parseDouble(closingStockField.getText());
                generateTrialBalance();
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Please enter a valid closing stock value!", "Error", JOptionPane.ERROR_MESSAGE);
            }
        });

        trialBalanceArea = new JTextArea();
        trialBalanceArea.setEditable(false);
        trialBalanceArea.setFont(MONOSPACE_FONT);
        JScrollPane scrollPane = new JScrollPane(trialBalanceArea);
        scrollPane.setBorder(BorderFactory.createTitledBorder(
            BorderFactory.createLineBorder(BORDER_COLOR),
            "Trial Balance",
            TitledBorder.LEFT,
            TitledBorder.TOP,
            HEADER_FONT,
            new Color(0, 0, 139)
        ));

        trialBalancePanel.add(inputPanel, BorderLayout.NORTH);
        trialBalancePanel.add(scrollPane, BorderLayout.CENTER);
    }

    private void createFinancialStatementsPanel() {
        financialStatementsPanel = new JPanel(new BorderLayout(10, 10));
        financialStatementsPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
        financialStatementsPanel.setBackground(PANEL_COLOR);

        JPanel bannerPanel = new JPanel(new BorderLayout());
        bannerPanel.setBackground(new Color(0, 60, 100));
        bannerPanel.setBorder(BorderFactory.createEmptyBorder(3, 15, 3, 15));

        JLabel bannerLabel = new JLabel("FINANCIAL STATEMENTS", SwingConstants.CENTER);
        bannerLabel.setForeground(Color.WHITE);
        bannerLabel.setFont(new Font("Segoe UI", Font.BOLD, 13));
        bannerPanel.add(bannerLabel, BorderLayout.CENTER);

        financialStatementsPanel.add(bannerPanel, BorderLayout.NORTH);

        JPanel contentPanel = new JPanel(new BorderLayout());
        contentPanel.setBackground(PANEL_COLOR);

        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.CENTER, 20, 10));
        buttonPanel.setBackground(PANEL_COLOR);

        generateFinancialStatementsButton = createStyledButton("Generate Financial Statements");
        generateFinancialStatementsButton.addActionListener(e -> generateFinancialStatements());
        buttonPanel.add(generateFinancialStatementsButton);

        contentPanel.add(buttonPanel, BorderLayout.NORTH);

        JPanel statementsPanel = new JPanel(new GridLayout(1, 3, 15, 15));
        statementsPanel.setBackground(PANEL_COLOR);
        statementsPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 20, 10));

        tradingAccountArea = createStyledTextArea("Trading Account");
        JScrollPane tradingScroll = createScrollPaneWithTitle(tradingAccountArea, "Trading Account");

        plAccountArea = createStyledTextArea("Profit & Loss Account");
        JScrollPane plScroll = createScrollPaneWithTitle(plAccountArea, "Profit & Loss Account");

        balanceSheetArea = createStyledTextArea("Balance Sheet");
        JScrollPane balanceScroll = createScrollPaneWithTitle(balanceSheetArea, "Balance Sheet");

        statementsPanel.add(tradingScroll);
        statementsPanel.add(plScroll);
        statementsPanel.add(balanceScroll);

        contentPanel.add(statementsPanel, BorderLayout.CENTER);
        financialStatementsPanel.add(contentPanel, BorderLayout.CENTER);
    }

    private JTextArea createStyledTextArea(String title) {
        JTextArea textArea = new JTextArea();
        textArea.setEditable(false);
        textArea.setFont(MONOSPACE_FONT);
        textArea.setBorder(BorderFactory.createEmptyBorder(5, 5, 5, 5));
        return textArea;
    }

    private JScrollPane createScrollPaneWithTitle(JTextArea textArea, String title) {
        JScrollPane scrollPane = new JScrollPane(textArea);
        scrollPane.setBorder(BorderFactory.createTitledBorder(
            BorderFactory.createLineBorder(FINANCIAL_STATEMENTS_COLOR, 2),
            title,
            TitledBorder.LEFT,
            TitledBorder.TOP,
            HEADER_FONT,
            FINANCIAL_STATEMENTS_COLOR
        ));
        return scrollPane;
    }

    private void updateLedgerComboBox() {
        ledgerAccountComboBox.removeAllItems();
        ArrayList<String> accountNames = new ArrayList<>(ledgerAccounts.keySet());
        Collections.sort(accountNames);
        for (String accountName : accountNames) {
            ledgerAccountComboBox.addItem(accountName);
        }
    }

    private void addJournalEntry(JComboBox<String> debitAccountTypeCombo, JComboBox<String> creditAccountTypeCombo) {
        try {
            String date = dateField.getText();
            String debitAccount = debitAccountField.getText().trim();
            String creditAccount = creditAccountField.getText().trim();
            double amount = Double.parseDouble(amountField.getText());
            String debitAccountType = (String) debitAccountTypeCombo.getSelectedItem();
            String creditAccountType = (String) creditAccountTypeCombo.getSelectedItem();

            if (debitAccount.isEmpty() || creditAccount.isEmpty()) {
                JOptionPane.showMessageDialog(this, "Account names cannot be empty!", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }

            if (amount <= 0) {
                JOptionPane.showMessageDialog(this, "Amount must be positive!", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }

            if (!ledgerAccounts.containsKey(debitAccount)) {
                ledgerAccounts.put(debitAccount, new LedgerAccount(debitAccount, debitAccountType));
            }

            if (!ledgerAccounts.containsKey(creditAccount)) {
                ledgerAccounts.put(creditAccount, new LedgerAccount(creditAccount, creditAccountType));
            }

            JournalEntry entry = new JournalEntry(date, debitAccount, creditAccount, amount);
            journalEntries.add(entry);

            ledgerAccounts.get(debitAccount).addDebit(amount);
            ledgerAccounts.get(creditAccount).addCredit(amount);

            updateJournalEntriesDisplay();
            updateLedgerComboBox();

            debitAccountField.setText("");
            creditAccountField.setText("");
            amountField.setText("");
            debitAccountField.requestFocus();

        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(this, "Please enter a valid amount!", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void updateJournalEntriesDisplay() {
        StringBuilder sb = new StringBuilder();

        sb.append(String.format("%-12s | %-40s | %-6s | %15s | %15s\n", 
            "Date", "Particulars", "L.F", "Dr. Amount (₹)", "Cr. Amount (₹)"));
        sb.append("-------------|------------------------------------------|--------|-----------------|-----------------\n");

        for (JournalEntry entry : journalEntries) {
            sb.append(String.format("%-12s | %-30s %9s | %-6s | %,15.2f | %15s\n", 
                entry.getDate(), 
                entry.getDebitAccount() + " A/c", 
                "Dr.", 
                "", 
                entry.getAmount(), 
                ""));

            sb.append(String.format("%-12s | %-40s | %-6s | %15s | %,15.2f\n", 
                "", 
                "To " + entry.getCreditAccount() + " A/c", 
                "", 
                "", 
                entry.getAmount()));

            sb.append(String.format("%-12s | %-40s | %-6s | %15s | %15s\n", 
                "", 
                "", 
                "", 
                "", 
                ""));
        }

        double totalDebit = journalEntries.stream().mapToDouble(JournalEntry::getAmount).sum();
        double totalCredit = totalDebit;

        sb.append(String.format("%-12s | %-40s | %-6s | %,15.2f | %,15.2f\n", 
            "Total", "", "", totalDebit, totalCredit));

        journalEntriesArea.setText(sb.toString());
    }

    private void viewLedger() {
        String selectedAccount = (String) ledgerAccountComboBox.getSelectedItem();
        if (selectedAccount == null) return;

        LedgerAccount account = ledgerAccounts.get(selectedAccount);

        StringBuilder sb = new StringBuilder();
        sb.append("LEDGER ACCOUNT: ").append(selectedAccount).append("\n");
        sb.append("ACCOUNT TYPE: ").append(account.getType()).append("\n\n");

        sb.append(String.format("%-12s | %-40s | %10s || %-12s | %-40s | %10s\n", 
            "Date", "Particulars", "Amount", "Date", "Particulars", "Amount"));
        sb.append("-------------+------------------------------------------+------------++--------------+------------------------------------------+------------\n");

        ArrayList<String> debitEntries = new ArrayList<>();
        ArrayList<String> creditEntries = new ArrayList<>();

        for (JournalEntry entry : journalEntries) {
            if (entry.getDebitAccount().equals(selectedAccount)) {
                debitEntries.add(String.format("%-12s | %-40s | %10.2f |",
                    entry.getDate(), "To " + entry.getCreditAccount(), entry.getAmount()));
            }
            if (entry.getCreditAccount().equals(selectedAccount)) {
                creditEntries.add(String.format("%-13s | %-40s | %10.2f |",
                    entry.getDate(), "By " + entry.getDebitAccount(), entry.getAmount()));
            }
        }

        double totalDebit = account.getTotalDebit();
        double totalCredit = account.getTotalCredit();
        double balance = Math.abs(account.getBalance());

        int maxRows = Math.max(debitEntries.size(), creditEntries.size());
        for (int i = 0; i < maxRows; i++) {
            String debitLine = i < debitEntries.size() ? debitEntries.get(i) : 
                String.format("%-12s | %-40s | %10s |", "", "", "");
            String creditLine = i < creditEntries.size() ? creditEntries.get(i) : 
                String.format("%-12s | %-40s | %10s |", "", "", "");
            sb.append(debitLine).append("|").append(creditLine).append("\n");
        }

        sb.append(String.format("%-12s | %-40s | %10s || %-12s | %-40s | %10s |\n",
            "", "", "", "", "", ""));

        boolean isDebitBalance = account.getType().equals("Asset") || account.getType().equals("Expense");
        if (isDebitBalance) {
            sb.append(String.format("%-12s | %-40s | %10s || %-12s | %-40s | %10.2f |\n",
                "", "", "", "", "By Balance b/d", balance));
        } else {
            sb.append(String.format("%-12s | %-40s | %10.2f || %-12s | %-40s | %10s |\n",
                "", "To Balance b/d", balance, "", "", ""));
        }

        sb.append(String.format("%-12s | %-40s | %10s || %-12s | %-40s | %10s |\n",
            "", "", "", "", "", ""));

        double adjustedDebitTotal = isDebitBalance ? totalDebit : totalDebit + balance;
        double adjustedCreditTotal = isDebitBalance ? totalCredit + balance : totalCredit;

        sb.append(String.format("%-12s | %-40s | %10.2f || %-12s | %-40s | %10.2f |\n",
            "", "Total", adjustedDebitTotal, "", "Total", adjustedCreditTotal));

        ledgerDetailsArea.setText(sb.toString());
    }

    private void generateTrialBalance() {
        trialBalance.clear();

        for (Map.Entry<String, LedgerAccount> entry : ledgerAccounts.entrySet()) {
            String accountName = entry.getKey();
            LedgerAccount account = entry.getValue();

            double balance = account.getBalance();
            if (balance != 0) {
                String type = account.getType();
                trialBalance.add(new TrialBalanceEntry(accountName, type, balance));
            }
        }

        Collections.sort(trialBalance, (a, b) -> {
            int typeCompare = a.getType().compareTo(b.getType());
            if (typeCompare != 0) return typeCompare;
            return a.getAccountName().compareTo(b.getAccountName());
        });

        displayTrialBalance();
    }

    private void displayTrialBalance() {
        StringBuilder sb = new StringBuilder();
        sb.append(String.format("%-30s | %-15s | %15s | %15s\n", 
            "Particulars", "Type", "Debit", "Credit"));
        sb.append("-------------------------------+-----------------+-----------------+-----------------\n");

        double totalDebit = 0;
        double totalCredit = 0;

        for (TrialBalanceEntry entry : trialBalance) {
            double debit = 0;
            double credit = 0;

            if (entry.getType().equals("Asset") || entry.getType().equals("Expense")) {
                debit = entry.getBalance();
                totalDebit += debit;
            } else {
                credit = entry.getBalance();
                totalCredit += credit;
            }

            sb.append(String.format("%-30s | %-15s | %15.2f | %15.2f\n", 
                entry.getAccountName(), entry.getType(), debit, credit));
        }

        sb.append("-------------------------------+-----------------+-----------------+-----------------\n");
        sb.append(String.format("%-30s | %-15s | %15.2f | %15.2f\n", 
            "", "Total", totalDebit, totalCredit));

        trialBalanceArea.setText(sb.toString());
    }

    private void generateFinancialStatements() {
        if (trialBalance.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Please generate Trial Balance first!", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        generateTradingAccount();
        generateProfitAndLossAccount();
        generateBalanceSheet();

        JOptionPane.showMessageDialog(this, "Financial statements generated successfully!", "Success", JOptionPane.INFORMATION_MESSAGE);
    }

    private void generateTradingAccount() {
        StringBuilder sb = new StringBuilder();
        sb.append("TRADING ACCOUNT\n");
        sb.append("For the period ending...\n\n");

        double purchases = ledgerAccounts.getOrDefault("Purchases", new LedgerAccount("Purchases", "Expense")).getBalance();
        double sales = ledgerAccounts.getOrDefault("Sales", new LedgerAccount("Sales", "Revenue")).getBalance();
        double costOfGoodsSold = purchases - closingStock;

        sb.append(String.format("%-40s %15.2f\n", "Sales", sales));
        sb.append(String.format("%-40s %15.2f\n", "Less: Cost of Goods Sold", costOfGoodsSold));
        sb.append("----------------------------------------+----------------\n");
        sb.append(String.format("%-40s %15.2f\n", "Gross Profit", sales - costOfGoodsSold));

        tradingAccountArea.setText(sb.toString());
    }

    private void generateProfitAndLossAccount() {
        StringBuilder sb = new StringBuilder();
        sb.append("PROFIT & LOSS ACCOUNT\n");
        sb.append("For the period ending...\n\n");

        double purchases = ledgerAccounts.getOrDefault("Purchases", new LedgerAccount("Purchases", "Expense")).getBalance();
        double sales = ledgerAccounts.getOrDefault("Sales", new LedgerAccount("Sales", "Revenue")).getBalance();
        double grossProfit = sales - (purchases - closingStock);

        sb.append(String.format("%-40s %15.2f\n", "Gross Profit", grossProfit));

        double otherRevenues = 0;
        for (TrialBalanceEntry entry : trialBalance) {
            if (entry.getType().equals("Revenue") && !entry.getAccountName().equals("Sales")) {
                sb.append(String.format("%-40s %15.2f\n", entry.getAccountName(), entry.getBalance()));
                otherRevenues += entry.getBalance();
            }
        }

        if (otherRevenues > 0) {
            sb.append(String.format("%-40s %15.2f\n", "Total Other Revenues", otherRevenues));
            sb.append(String.format("%-40s %15.2f\n", "Total Revenue", grossProfit + otherRevenues));
        }

        double totalExpenses = 0;
        sb.append("\nLess: Expenses\n");
        for (TrialBalanceEntry entry : trialBalance) {
            if (entry.getType().equals("Expense") && !entry.getAccountName().equals("Purchases")) {
                sb.append(String.format("%-40s %15.2f\n", entry.getAccountName(), entry.getBalance()));
                totalExpenses += entry.getBalance();
            }
        }

        sb.append("----------------------------------------+----------------\n");
        sb.append(String.format("%-40s %15.2f\n", "Total Expenses", totalExpenses));
        sb.append("----------------------------------------+----------------\n");
        double netProfit = grossProfit + otherRevenues - totalExpenses;
        sb.append(String.format("%-40s %15.2f\n", "Net Profit", netProfit));

        plAccountArea.setText(sb.toString());
    }

    private void generateBalanceSheet() {
        StringBuilder sb = new StringBuilder();
        sb.append("BALANCE SHEET\n");
        sb.append("As at...\n\n");

        sb.append("ASSETS\n");
        double totalAssets = 0;

        if (closingStock > 0) {
            sb.append(String.format("%-40s %15.2f\n", "Closing Stock", closingStock));
            totalAssets += closingStock;
        }

        for (TrialBalanceEntry entry : trialBalance) {
            if (entry.getType().equals("Asset") && !entry.getAccountName().equals("Closing Stock")) {
                sb.append(String.format("%-40s %15.2f\n", entry.getAccountName(), entry.getBalance()));
                totalAssets += entry.getBalance();
            }
        }
        sb.append("----------------------------------------+----------------\n");
        sb.append(String.format("%-40s %15.2f\n", "Total Assets", totalAssets));

        sb.append("\nLIABILITIES\n");
        double totalLiabilities = 0;
        for (TrialBalanceEntry entry : trialBalance) {
            if (entry.getType().equals("Liability")) {
                sb.append(String.format("%-40s %15.2f\n", entry.getAccountName(), entry.getBalance()));
                totalLiabilities += entry.getBalance();
            }
        }
        sb.append("----------------------------------------+----------------\n");
        sb.append(String.format("%-40s %15.2f\n", "Total Liabilities", totalLiabilities));

        sb.append("\nOWNER'S EQUITY\n");
        double capital = ledgerAccounts.getOrDefault("Capital", new LedgerAccount("Capital", "Equity")).getBalance();
        double drawings = ledgerAccounts.getOrDefault("Drawings", new LedgerAccount("Drawings", "Equity")).getBalance();

        double purchases = ledgerAccounts.getOrDefault("Purchases", new LedgerAccount("Purchases", "Expense")).getBalance();
        double sales = ledgerAccounts.getOrDefault("Sales", new LedgerAccount("Sales", "Revenue")).getBalance();
        double grossProfit = sales - (purchases - closingStock);

        double otherRevenues = 0;
        for (TrialBalanceEntry entry : trialBalance) {
            if (entry.getType().equals("Revenue") && !entry.getAccountName().equals("Sales")) {
                otherRevenues += entry.getBalance();
            }
        }

        double totalExpenses = 0;
        for (TrialBalanceEntry entry : trialBalance) {
            if (entry.getType().equals("Expense") && !entry.getAccountName().equals("Purchases")) {
                totalExpenses += entry.getBalance();
            }
        }

        double netProfit = grossProfit + otherRevenues - totalExpenses;

        sb.append(String.format("%-40s %15.2f\n", "Capital", capital));
        sb.append(String.format("%-40s %15.2f\n", "Add: Net Profit", netProfit));
        sb.append(String.format("%-40s %15.2f\n", "Less: Drawings", drawings));
        sb.append("----------------------------------------+----------------\n");
        sb.append(String.format("%-40s %15.2f\n", "Total Equity", capital + netProfit - drawings));
        sb.append("----------------------------------------+----------------\n");
        sb.append(String.format("%-40s %15.2f\n", "Total Liabilities & Equity", totalLiabilities + capital + netProfit - drawings));

        balanceSheetArea.setText(sb.toString());
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            try {
                UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
            } catch (Exception e) {
                e.printStackTrace();
            }

            AccountingSoftware software = new AccountingSoftware();
            software.setVisible(true);
        });
    }

    class JournalEntry {
        private String date;
        private String debitAccount;
        private String creditAccount;
        private double amount;

        public JournalEntry(String date, String debitAccount, String creditAccount, double amount) {
            this.date = date;
            this.debitAccount = debitAccount;
            this.creditAccount = creditAccount;
            this.amount = amount;
        }

        public String getDate() { return date; }
        public String getDebitAccount() { return debitAccount; }
        public String getCreditAccount() { return creditAccount; }
        public double getAmount() { return amount; }
    }

    class LedgerAccount {
        private String name;
        private String type;
        private double totalDebit;
        private double totalCredit;

        public LedgerAccount(String name, String type) {
            this.name = name;
            this.type = type;
            this.totalDebit = 0;
            this.totalCredit = 0;
        }

        public void addDebit(double amount) {
            totalDebit += amount;
        }

        public void addCredit(double amount) {
            totalCredit += amount;
        }

        public double getBalance() {
            if (type.equals("Asset") || type.equals("Expense")) {
                return totalDebit - totalCredit;
            } else {
                return totalCredit - totalDebit;
            }
        }

        public String getName() { return name; }
        public String getType() { return type; }
        public double getTotalDebit() { return totalDebit; }
        public double getTotalCredit() { return totalCredit; }
    }

    class TrialBalanceEntry {
        private String accountName;
        private String type;
        private double balance;

        public TrialBalanceEntry(String accountName, String type, double balance) {
            this.accountName = accountName;
            this.type = type;
            this.balance = balance;
        }

        public String getAccountName() { return accountName; }
        public String getType() { return type; }
        public double getBalance() { return balance; }
    }
}